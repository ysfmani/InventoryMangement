#ifndef PANIER_H
#define PANIER_H

#include <QObject>
#include <QVector>
#include "equipement.h"

class panier
{
public:
    QVector<Equipement*> tabEq;
    void Ajouter(Equipement*);
    void Supprimer(Equipement*);
    int rechercher(QString);
    panier();
    ~panier();
};

#endif // PANIER_H
