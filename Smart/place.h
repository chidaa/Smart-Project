#ifndef PLACE_H
#define PLACE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Place
{
public:
    Place();
    Place(int,QString,QString);
    int get_num_place();
    QString get_type_place();
    QString get_etat();
    bool ajouter_place();
    QSqlQueryModel * afficher_place();
    bool supprimer_place(int);
    bool modifier(int);
private:
   int num;
   QString type_p,etat;
};

#endif // PLACE_H
