#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include "connexion.h"
#include "user.h"
namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();
public slots:
    void LoginVerif(int);
    void dest(bool);
signals:
    void util(User& u);
    void Connect(QString,QString);
    void Done(bool);
private slots:
    void on_seConnecter_clicked();

    void on_oublie_clicked();

private:
    Connexion conn;
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
