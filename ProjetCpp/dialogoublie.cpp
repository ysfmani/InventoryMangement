#include "dialogoublie.h"
#include "ui_dialogoublie.h"

Dialogoublie::Dialogoublie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogoublie)
{
    ui->setupUi(this);
}

Dialogoublie::~Dialogoublie()
{
    delete ui;
}
