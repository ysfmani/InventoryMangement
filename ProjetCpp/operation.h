#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include "connexion.h"
#include "operation.h"

class operation
{
int numOp;
QString dateOp;
QString descOp;
int typeOp;
QString idPers;
int etat;
public:
    operation();
    int getnum(){return numOp;}
    QString getdate(){return dateOp;}
    QString getdesc(){return descOp;}
    int getType(){return typeOp;}
    int getetat(){return etat;}
    QString getid(){return idPers;}
    void setnum(int x){numOp = x;}
    void setdate(QString x){dateOp=x;}
    void setdesc(QString x){descOp = x;}
    void settype(int x){typeOp = x;}
    void setid(QString x){idPers = x;}
    bool ajouterBD();

};

#endif // OPERATION_H
