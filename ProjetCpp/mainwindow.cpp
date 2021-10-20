#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "connexion.h"
#include "demande.h"
#include "profile.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    conn.ouvrirConnexion();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    conn.fermerConnexion();
    delete ui;
}

//void MainWindow::setShow(bool v){
//    if (v) {
//        this->show();
//        conn.ouvrirConnexion(); }
//    emit isOpen(v);
//}

void MainWindow::on_Button1_clicked()
{
    qDebug()<<"!page 1 UP ";
    QWidget * pt = ui->stacked->widget(1);
    ui->stacked->removeWidget(ui->stacked->widget(1));
    pt->deleteLater();
    Profile * p = new Profile;
    p->setCurr(currUser);
    ui->stacked->insertWidget(0,p);
    ui->stacked->setCurrentIndex(0);
}

void MainWindow::on_Button2_clicked()
{
    QWidget * pt = ui->stacked->widget(0);
    pt->deleteLater();
    ui->stacked->removeWidget(ui->stacked->widget(0));
    Demande* d = new Demande;
    QObject::connect(d,&Demande::demandeDone,this,&MainWindow::on_Button1_clicked);
    d->setUser(currUser);
    ui->stacked->insertWidget(1,d);
    ui->stacked->setCurrentIndex(1);
}

