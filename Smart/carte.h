#ifndef CARTE_H
#define CARTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Carte
{public:
    Carte();
    Carte(int,int,QString);
    QString get_datee();
    int get_id();
    int get_point();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,int);

private:
    QString datee;
    int id,point;
};

#endif // CLIENT_H
