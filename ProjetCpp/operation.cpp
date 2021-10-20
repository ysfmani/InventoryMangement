#include "operation.h"

operation::operation()
{
QString prep = "select MAX(numop) from operation";
QSqlQuery qry;
qry.prepare(prep);
qry.exec();
qry.seek(0);
numOp = qry.value(0).toInt()+1;
etat = 0;
}
bool operation::ajouterBD(){
    bool b;
    QString prep = "INSERT INTO OPERATION VALUES(%1,DEFAULT,'%2',%3,'%4')";
    QString check = "SELECT * from OPERATION WHERE numop = %1";
    QSqlQuery qryInsert;
    QSqlQuery qryCheck;
    prep = prep.arg(QString::number(numOp),descOp,QString::number(typeOp),idPers);
    check = check.arg(QString::number(numOp));
    //Check if exists
    qryCheck.prepare(check);
    qryCheck.exec();
    qDebug()<< "Taille du Qry" << qryCheck.size();
    int count=0;
    while(qryCheck.next()){
        count++;
    }
    if (count==0){
        qryInsert.prepare(prep);
        qryInsert.exec();
        b = true;
    }
    else{
        b = false;
    }
    return b;
}
