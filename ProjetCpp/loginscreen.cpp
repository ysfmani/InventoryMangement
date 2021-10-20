#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "qfontdatabase.h"
#include <QInputDialog>
#include <QChar>
#include "smtp.h"
#include "user.h"
LoginScreen::LoginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginScreen)
{
    QFontDatabase::addApplicationFont(":/login/images/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/login/images/Roboto-Bold.ttf");
    ui->setupUi(this);
    this->setWindowTitle("Se Connecter");
    this->setWindowIcon(QIcon(":/login/images/icon.ico"));
    QObject::connect(ui->lineMDP,&QLineEdit::returnPressed,ui->seConnecter,&QPushButton::click);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_seConnecter_clicked()
{
    QString a = ui->lineID->text();
    QString b = ui->lineMDP->text();
    emit  Connect(a,b);
}
void LoginScreen::LoginVerif(int v){
    QString Message;
    if(v != 0){
    if (v == 1){Message = " Mot De Passe Incorrect !";}
    else if (v == -1){Message = " Cet ID N'Existe Pas !";}
        ui->labConn->setText(Message);
        ui->labConn->setStyleSheet("color: red;");
        }
    else {
                this->close();
        emit Done(true);

    }
}
void LoginScreen::dest(bool v){
    if (v) this->deleteLater();
}

void LoginScreen::on_oublie_clicked()
{

    bool ok;
    QString Email;
    QString desc = QInputDialog::getText(0, "Donnez Votre Email",
                                             "Donnez Votre Email:", QLineEdit::Normal,
                                             "user@host.com", &ok);
    if (ok && !desc.isEmpty()) {
    Email = desc;
    QString nom = User::checkmail(Email);
    if(nom == ""){
        QMessageBox messageBox;
        messageBox.critical(this,"Error","Email Non trouvé !");
    }
    else{

        srand(time(0));
        QChar x = 97 + rand() % 26;
        QChar y = 97 + rand() % 26;
        QChar z = 97 + rand() % 26;
        QChar f = 97 + rand() % 26;
        QString code ;
        code.reserve(4);
        code.append(x).append(y).append(z).append(f);
        qDebug()<<code;
        Smtp * smtp = new Smtp("no.reply.reset.tpcpp@gmail.com", "tpcpp2631", "smtp.gmail.com");

        smtp->sendMail("no.reply.reset.tpcpp@gmail.com", Email , "MyCompany Password Reset","Bonjour "+nom+",\nVotre Code de Sécurité est "+code);

        QString Reponse = QInputDialog::getText(this, "Reset Code",
                                                "Verifier votre Email et Entrer le Code :", QLineEdit::Normal,
                                                "", &ok);
        if (ok && !Reponse.isEmpty()) {
        if(Reponse == code){
            QString nvMdp = QInputDialog::getText(this, "Reset Code",
                                                  "Entrer Votre nouveau mot de passe :", QLineEdit::Normal,
                                                  "", &ok);
            if (ok && !Reponse.isEmpty()) {
                bool b = User::mdpReset(Email,nvMdp);
                if(b)             QMessageBox::information(this, "Done !", "Votre mdp est changé") ;
            }


        }
        else{
            QMessageBox messageBox;
            messageBox.critical(this,"Error","Code Incorrect Ressayer svp !!");
        }


    }


        }
}}
