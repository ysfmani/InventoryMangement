#include "mainwindow.h"
#include "loginscreen.h"
#include <QApplication>
#include "user.h"
#include "equipement.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    User currUser; // l'objet de l'utilisateur;
    LoginScreen* Log = new LoginScreen;//fentre de connexion;
    Log->show();
    MainWindow* Main = new MainWindow;

//Connections between Log and Main:
    QObject::connect(Log,&LoginScreen::Connect,&currUser,&User::Check); // chechk l'Id et mdp
    QObject::connect(&currUser,&User::CheckResult,Log,&LoginScreen::LoginVerif);
    //changer login apres verif
    QObject::connect(Log,&LoginScreen::Done,&currUser,&User::Done);
    QObject::connect(&currUser,&User::gotcha,Log,&LoginScreen::dest);

    //Cureent user in all widgets
    QObject::connect(&currUser,&User::util,Main,&MainWindow::setCurr);

    //changer login apres verif
    // si verifier afficher main    //
    return a.exec();
}
