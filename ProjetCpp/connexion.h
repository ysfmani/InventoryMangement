#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>


class Connexion
{
public:
    QSqlDatabase db;
    Connexion();
    bool ouvrirConnexion();
   void fermerConnexion();
};

#endif // CONNEXION_H
