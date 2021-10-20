#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "user.h"
namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    void setCurr(User);
    void chargerEnCours();
    ~Profile();

private:
    User currUser;
    Ui::Profile *ui;
};

#endif // PROFILE_H
