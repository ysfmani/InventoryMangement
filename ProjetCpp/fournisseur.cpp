/*#include "fournisseur.h"
#include "connexion.h"
Fournisseur::Fournisseur()
{


}
void Fournisseur::Charger(QString id){
    QString check = "SELECT * FROM FOURNISSUER WHERE IDFOUR = '%1'";
    QMap<QString,infoFour>::iterator it;
    it=profile.begin();
    check=check.arg(id);
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
           QPair<QString,infoFour> pair;
           pair.first = id;
           pair.second
           setNom(qryCheck.value(1).toString());
           setPrenom(qryCheck.value(2).toString());
           setPoste(qryCheck.value(3).toString());
           qDebug()<<"im here";
           return 0;
         // si le mdp est conforme
       else {
return 1;} // mdp non conforme
    }
    else if (count == 0){
        return -1;// id n'existe pas 0 ligne
    }
    return 2;
}
*/
