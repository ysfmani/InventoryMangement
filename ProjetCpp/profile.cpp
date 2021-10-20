#include "profile.h"
#include "ui_profile.h"
#include "connexion.h"
#include <QDebug>
Profile::Profile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    qDebug()<<"Destroying profile";
    delete ui;
}
void Profile::setCurr(User u){
    currUser = u;
    ui->Nom->setText(currUser.getNom()+" "+currUser.getPrenom());
    ui->Poste->setText(currUser.getPoste());
    qDebug()<<currUser.getNom()<<currUser.getPoste();
    ui->ListDemande->clear();
    chargerEnCours();

}
void Profile::chargerEnCours(){
    QString prep = "select * from operation where numop not in (select numop from opaccept) and operation.idpers = '%1'";
    prep = prep.arg(currUser.getID());
    QSqlQuery qry;
    qry.prepare(prep);
    qry.exec();
    QString item ="";
    while(qry.next()){
       item += "Date : " + qry.value(1).toString() +" | Desc : " + qry.value(2).toString();
       qDebug() <<"qry" << qry.value(1).toString();
       qDebug() <<"item : "<<item;
      ui->ListDemande->addItem(item);
      item="";
    }

}
