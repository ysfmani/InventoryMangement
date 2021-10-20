#include "connexion.h"

Connexion::Connexion()
{
}
bool Connexion::ouvrirConnexion(){
    qDebug()<<"Opening BD..";
    bool test = false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet");
    db.setUserName("TPBD");
    db.setPassword("12345");
    if(db.open()) {test = true;
    qDebug()<<"Opened!";}
    else qDebug()<< "Erreur = " << db.lastError().text();
    return test;
}

void Connexion::fermerConnexion(){
    qDebug()<<"clossing BD";
    db.close();
}
