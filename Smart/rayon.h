#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Rayon
{public:
    Rayon();
    Rayon(int,QString,int,QString);
    QString get_type_2();
    int get_etat();
    QString get_materiels();
    int get_id_3();

    bool ajouter_2();
    QSqlQueryModel * afficher();
    bool supprimer_2(int);
    bool modifier_2(int);
    QSqlQueryModel * recherche_2(const QString &id_3);
    QSqlQueryModel * afficher_trier();
private:
    QString type_2;
    int id_3;
    int etat;
    QString materiels;
};

#endif //RAYON_H
