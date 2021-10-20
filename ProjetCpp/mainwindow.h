#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connexion.h"
#include "user.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    User currUser;
    ~MainWindow();
public slots:
   //void setShow(bool);
   void  setCurr(User* u){currUser = *u;
                          on_Button1_clicked();
                         this->show();}
signals:
   void isOpen(bool);
private slots:
   void on_Button1_clicked();

   void on_Button2_clicked();
private:
   Connexion conn;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
