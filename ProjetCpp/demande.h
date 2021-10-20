#ifndef DEMANDE_H
#define DEMANDE_H

#include <QWidget>
#include "connexion.h"
#include "panier.h"
#include <QListWidgetItem>
#include "user.h"
#include "operation.h"

namespace Ui {
class Demande;
}

class Demande : public QWidget
{
    Q_OBJECT

public:
    explicit Demande(QWidget *parent = nullptr);
    void ChangerSub(int);
    void setUser(User curr);
    ~Demande();
signals:
    void demandeDone();
private slots:
    void on_searchBut_clicked();
    void on_Ajout_Panier_clicked();

    void on_categorie_currentIndexChanged(int index);
    void on_listPanier_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    operation op;
    panier p;
    User currUser;
    //Connexion conn;
    Ui::Demande *ui;
};

#endif // DEMANDE_H
