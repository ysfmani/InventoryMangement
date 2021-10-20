#ifndef INFOFOUR_H
#define INFOFOUR_H

#include <QObject>

class infoFour
{
    QString Nom;
    QString Adresse;
    int Num_tel;
public:
    void setNom(QString x){Nom =x;}
    void setAdresse(QString x){Adresse =x;}
    void setNum(int x){Num_tel = x;}
    void setAll(QString x, QString y,int num){setNom(x);setAdresse(y);setNum(num);}
    QString getNom(){return Nom;}
    QString getAdresse(){return Adresse;}
    int getNum(){return Num_tel;}
    infoFour(QString ="",QString="",int =0);
};

#endif // INFOFOUR_H
