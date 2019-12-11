#ifndef CAISSE_H
#define CAISSE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Caisse
{public:
    Caisse();
    Caisse(int,QString,int,QString);
    QString get_type();
    int get_quantite();
    int get_id();
    QString get_prix();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *rechercher(QString c);
    QSqlQueryModel *calcul_prix_total(int id);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * afficher_trier1();
    QSqlQueryModel* calcul_prix_total(QString ref);
    QSqlQueryModel* calcul_total();

private:
    QString type;
    int id;
    QString prix;
    int quantite;
};

#endif //CAISSE_H
