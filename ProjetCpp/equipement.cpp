#include "equipement.h"
#include "connexion.h"
Equipement::Equipement()
{
quant = 0;
}
// FIX AJOUTER !!!!!!!
int Equipement::Ajouter(){
    int b;
    QString prep = "INSERT INTO EQUIPEMENT VALUES('%1','%2',DEFAULT,'%3','%4','%5')";
    QString check = "SELECT * from Personnel WHERE IDPERS = '%1'";
    QSqlQuery qryInsert;
    QSqlQuery qryCheck;
    prep = prep.arg(idEq,libEq,marque,emplacementEq,QString::number(prix_achat),QString::number(typeEq),QString::number(etat));
    //check = check.arg(id);
    //Check if exists
    qryCheck.prepare(check);
    qryCheck.exec();
    int count=0;
    while(qryCheck.next()){
        count++;
    }
    qryCheck.size();
    if (count==0){
        qryInsert.prepare(prep);
        qryInsert.exec();
        b = 1;
    }
    else{
        b = 0;
    }
    return b;
}
int Equipement::Charger(QString identifiant){
    QString prep = "Select * From EQUIPEMENT where ideq like '%1';";
    prep = prep.arg(identifiant);
    qDebug()<<prep;
    QSqlQuery qry;
    qry.prepare(prep);
    qry.exec();
    qry.seek(0);
    qDebug()<<qry.value(0).toString();
    setid(qry.value(0).toString());
    setlib(qry.value(1).toString());
    setDate(qry.value(2).toString());
    setMarque(qry.value(3).toString());
    setEmp(qry.value(4).toString());
    setprix(qry.value(5).toFloat());
    settype(qry.value(6).toInt());
    setetat(qry.value(7).toInt());
    //qDebug()<<idEq<< libEq<<date_ajout<<marque<<emplacementEq<<prix_achat<<typeEq<<etat;
    return 1;
}
QString Equipement::toString(){
    QString res;
    QString quanttt = " Quantité = ";
    res.reserve(idEq.length() + 3 + libEq.length()+quanttt.length()+QString::number(quant).length());
    res.append(idEq);
    res.append(":  ");
    res.append(libEq);
    res.append(quanttt);
    res.append(QString::number(quant));
    qDebug()<<"check resultat = "<<res;
    return res;
}
