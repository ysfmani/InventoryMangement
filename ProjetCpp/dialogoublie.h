#ifndef DIALOGOUBLIE_H
#define DIALOGOUBLIE_H

#include <QDialog>

namespace Ui {
class Dialogoublie;
}

class Dialogoublie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogoublie(QWidget *parent = nullptr);
    ~Dialogoublie();

private:
    Ui::Dialogoublie *ui;
};

#endif // DIALOGOUBLIE_H
