#ifndef USER_H
#define USER_H
#include <QString>
#include <QObject>

class User:public QObject
{
    Q_OBJECT
public slots:
    void Check(QString,QString);
    void Done(bool);
signals:
    void CheckResult(int);
    void util(User*);
    void gotcha(bool);
public:
    User(User&);
    User(QString="",QString="",QString="",QString="",QString="");
    int Charger(QString,QString);
    bool Ajouter();
    bool Supprimer();
    void setID(QString a ){id=a;}
    void setNom(QString a){nom=a;}
    void setPrenom(QString a){prenom=a;}
    void setPoste(QString a){poste=a;}
    void setMdp(QString a){mdp=a;}
    QString getID(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getPoste(){return poste;}
    QString getMdp(){return mdp;}
    bool operator=(User&);
    static QString checkmail(QString);
    static bool mdpReset(QString,QString);

private:
    QString id;
    QString nom;
    QString prenom;
    QString poste;
    QString mdp;

};

#endif // USER_H
