#ifndef FOUR_H
#define FOUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class four
{public:
    four();
    four(int,int,QString,QString,QString);

    int get_idfourn();
    int get_numtel();
    QString get_nomfourn();
     QString get_prenomfourn();
      QString get_catprod();
    bool ajouter_3();
    QSqlQueryModel * afficher_2();
    bool supprimer_2(int);
    bool modifier_2(int idcom);
    QSqlQueryModel * rechercher(const QString &idcom);
    QSqlQueryModel * afficher_trier();
private:
    QString catprod;
    QString nomfourn;
    QString prenomfourn;
    int numtel;
    int idfourn;
};

#endif //FOUR_H
