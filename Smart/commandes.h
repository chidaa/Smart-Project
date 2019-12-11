#ifndef COMMANDES_H
#define COMMANDES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Commandes
{public:
    Commandes();
    Commandes(QString,int,int);

    int get_idfourn();
    int get_idcom();
    QString get_catprod();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int idcom);
    QSqlQueryModel * rechercher(const QString &idcom);
    QSqlQueryModel * afficher_trier();

private:
    QString catprod;
    int idcom;
    int idfourn;
};

#endif //COMMANDES_H
