#include "user.h"
#include "connexion.h"
User::User(QString x,QString y,QString z,QString e,QString f)
{
id =x;
nom=y;
prenom=z;
poste=e;
mdp=f;
}
bool User::Ajouter(){
    bool b;
    QString prep = "INSERT INTO PERSONNEL VALUES('%1','%2','%3','%4','%5')";
    QString check = "SELECT * from Personnel WHERE IDPERS = '%1'";
    QSqlQuery qryInsert;
    QSqlQuery qryCheck;
    prep = prep.arg(id,nom,prenom,poste,mdp);
    check = check.arg(id);
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
bool User::operator=(User &u){
    id= u.id;
    nom= u.nom;
    prenom = u.prenom;
    poste= u.poste;
    mdp = u.mdp;
    return true;
}
User::User(User &u){
    id= u.id;
    nom= u.nom;
    prenom = u.prenom;
    poste= u.poste;
    mdp = u.mdp;
}

QString User::checkmail(QString mail){
    QString check = "SELECT * FROM PERSONNEL WHERE EMAIL = '%1'";
    check=check.arg(mail);
    QSqlQuery qryCheck;
    qryCheck.prepare(check);
    qryCheck.exec();
    int count=0;
    while(qryCheck.next()){
        count++;
    }
    if (count == 1){
qryCheck.seek(0);
QString mail =qryCheck.value(1).toString();
qryCheck.finish();
return mail;
    }
    else return "";
}
int User::Charger(QString Identifiant,QString m){

    QString check = "SELECT * FROM PERSONNEL WHERE IDPERS = '%1'";
    check=check.arg(Identifiant);
    QSqlQuery qryCheck;
    qryCheck.prepare(check);
    qryCheck.exec();
    qDebug()<<qryCheck.lastQuery();
    //compter nombre des lignes
    int count=0;
    while(qryCheck.next()){
        count++;
    }
    qryCheck.seek(0);//retour au debut
    if (count==1){// si il trouve 1 ligne ( cet id)
       if(qryCheck.value(4).toString() == m){
           setID(Identifiant);
           setMdp(m);
           setNom(qryCheck.value(1).toString());
           setPrenom(qryCheck.value(2).toString());
           setPoste(qryCheck.value(3).toString());
           qDebug()<<"im here";
           return 0;
       }  // si le mdp est conforme
       else {
return 1;} // mdp non conforme
    }
    else if (count == 0){
        return -1;// id n'existe pas 0 ligne
    }
    return 2;
}
void User::Check(QString a,QString b){
     int v =  Charger(a,b);
     emit CheckResult(v);
     qDebug()<< getID();
}
void User::Done(bool v){
    if(v) {emit util(this);
    emit gotcha(v);}
}
bool User::mdpReset(QString mail, QString mdpp){
    QString prep = "UPDATE  Personnel SET  MDP = '%1' WHERE Email = '%2'";
    prep=prep.arg(mdpp,mail);
    qDebug()<<prep;
    QSqlQuery qryCheck;
    qryCheck.prepare(prep);

    qDebug()<<"preparé!";
return qryCheck.exec();}

