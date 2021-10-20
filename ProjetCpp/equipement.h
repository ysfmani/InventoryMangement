#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QObject>

class Equipement
{
    QString idEq;
    QString libEq;
    QString date_ajout;
    QString marque;
    QString emplacementEq;
    float prix_achat;
    int typeEq;
    int etat;
    int quant;
public:
    QString getid(){return idEq;}
    int getquant(){return quant;}
    void QuantUp(){quant++;}
    void QuantDown(){quant--;}
    int Ajouter();
    int Charger(QString);
    int Supprimer();
    void setid(QString x){idEq = x;}
    void setlib(QString x){libEq = x;}
    void setDate(QString x){date_ajout = x;}
    void setMarque(QString x){marque = x;}
    void setEmp(QString x){emplacementEq = x;}
    void setprix(float x){prix_achat = x;}
    void settype(int x){typeEq = x;}
    void setetat(int x){etat = x;}
    QString toString();
    Equipement();
};

#endif // EQUIPEMENT_H
