#include "demande.h"
#include "ui_demande.h"
#include "mainwindow.h"
#include "QInputDialog"
Demande::Demande(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demande)
{
    ui->setupUi(this);
   QObject::connect(ui->LineLib,&QLineEdit::returnPressed,ui->searchBut,&QPushButton::click);
    QObject::connect(ui->LineMarque,&QLineEdit::returnPressed,ui->searchBut,&QPushButton::click);
    QObject::connect(ui->LineRef,&QLineEdit::returnPressed,ui->searchBut,&QPushButton::click);
    ui->subCategorie->hide();
    ui->lineAutre->hide();
    ui->labType->hide();
   // ui->Ajout_Panier->setEnabled(false);
}
Demande::~Demande()
{
    delete ui;
}
void Demande::ChangerSub(int curr){
    ui->subCategorie->clear();
    ui->subCategorie->hide();
    ui->lineAutre->hide();
    ui->labType->hide();
    switch (curr){
    case 1:
        ui->labType->show();
        ui->subCategorie->addItem("");
        ui->subCategorie->addItem("Fixe");
        ui->subCategorie->addItem("Portable");
        ui->subCategorie->show();
        break;
    case 2:
        ui->labType->show();
        ui->subCategorie->addItem("");
        ui->subCategorie->addItem("Routeur");
        ui->subCategorie->addItem("Commutateur");
        ui->subCategorie->addItem("Autre");
        ui->subCategorie->show();
        break;
    case 3:
        ui->labType->show();
        ui->subCategorie->addItem("");
        ui->subCategorie->addItem("Ecran");
        ui->subCategorie->addItem("Clavier");
        ui->subCategorie->addItem("Souris");
        ui->subCategorie->addItem("Imprimante/Scanner");
        ui->subCategorie->show();
        break;
    case 4:
        ui->lineAutre->show();
        ui->labType->show();
        break;
    }

}
void Demande::on_searchBut_clicked()
{
    QString prep = "Select IDEQ as \"Réference\",LIBEQ as \"Libelé\",MARQUE,ETAT from EQUIPEMENT "
                   "Where upper(ideq) like upper('%%1%') and upper(libeq) like upper('%%2%') "
                   "and upper(marque) like upper('%%3%');";
    prep = prep.arg(ui->LineRef->text(),ui->LineLib->text(),ui->LineMarque->text());
    qDebug()<<prep;
    qDebug()<<ui->LineRef->text()<<ui->LineLib->text();
    QSqlQuery qry;
    qry.prepare(prep);
    qry.exec();
    QSqlQueryModel *Model = new QSqlQueryModel();
    Model->setQuery(qry);
    ui->tableView->setModel(Model);
    ui->tableView->show();
    qDebug()<<Model->rowCount();
    qry.clear();
}

void Demande::on_Ajout_Panier_clicked()
{
    if(ui->tableView->currentIndex().isValid()){
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows(0);
    qDebug()<<selection.count();
    for(int j=0; j< selection.count(); j++)
    {
        bool v=true;
        QModelIndex index = selection.at(j);
        QString Identifiant = index.data().toString();
        Equipement* eq = new Equipement;
        eq->Charger(Identifiant);
        //verifier l existance dans le panier
        for (int i=0;i<p.tabEq.size();i++) {
            if(eq->getid()==p.tabEq[i]->getid()) v=false;
        }
        if(v) {
               //si non ajouter
            eq->QuantUp();
            p.Ajouter(eq);
        ui->listPanier->addItem(eq->toString());}
        else{
            // si oui augmenter quantite
            int index = p.rechercher(eq->getid());
            if(index!=-1){
                p.tabEq[index]->QuantUp();

                for(int i=0;i < ui->listPanier->count();i++){
                    if(ui->listPanier->item(i)->text().contains(eq->getid())){
                        ui->listPanier->item(i)->setText(p.tabEq[index]->toString());
                    }
                }
            }
        }

    }
    }
}

void Demande::on_categorie_currentIndexChanged(int index)
{
    ChangerSub(index);
}



void Demande::on_listPanier_itemDoubleClicked(QListWidgetItem *item)
{
    QString quant = "Quantité = ";
    int index = item->data(0).toString().indexOf("Quantité = ");
    index += quant.length();
    QString current = item->data(0).toString();
    int quantite = current.mid(index,1).toInt();
    int row = ui->listPanier->row(item);
    if(quantite ==1){
        quantite--;
        qDebug()<<p.tabEq[row]->getid()<<p.tabEq[row]->getquant()-1;
        p.tabEq.remove(row);
        ui->listPanier->takeItem(row);
    }
    else {quantite--;
        p.tabEq[row]->QuantDown();
    current.replace(index,1,QString::number(quantite));
    item->setText(current);
        qDebug()<<p.tabEq[row]->getid()<<p.tabEq[row]->getquant();}


}

void Demande::on_pushButton_clicked()
{
    operation * op = new operation;
    qDebug()<< "Operation crée";
    qDebug()<< op->getnum() << " est le numOp";
    op->setid(currUser.getID());
    op->settype(0);
    bool ok;
    QString desc = QInputDialog::getText(0, "Description du Demande",
                                             "Description de la Demande :", QLineEdit::Normal,
                                             "Pas de Notes", &ok);
    if (ok && !desc.isEmpty()) {
    op->setdesc(desc);
        }
    else op->setdesc("Pas de Notes");
    op->ajouterBD();
    qDebug()<<"Ajouté avec succ au BD";
 ui->listPanier->clear();
 // ajouter la composition de la demande
 QString prep2;
 QSqlQuery qry2;
 for (int i=0;i<p.tabEq.size();i++) {
     prep2 = "INSERT INTO LIGNECOMP VALUES(%1,'%2', %3);";
     prep2 = prep2.arg(QString::number(op->getnum()),p.tabEq[i]->getid(),QString::number(p.tabEq[i]->getquant()));
     qry2.prepare(prep2);
     qry2.exec();
     qry2.clear();

 }
 delete op;
 emit demandeDone();
}
void Demande::setUser(User u){
    currUser = u;
}

void Demande::on_tableView_doubleClicked(const QModelIndex &)
{
    on_Ajout_Panier_clicked();
}
