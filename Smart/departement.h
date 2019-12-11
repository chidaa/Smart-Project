#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class departement
{
public:
    departement();
    departement(int,QString,int,int);
    QString get_nom();
    int get_departement_id();
    int get_manager_id();
    int get_num_membre();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_personnel_trier();
    QSqlQueryModel * rechercher_personnel(const QString &id);
    bool supprimer(int);
    bool ajouter();
    bool modifier(int );
private:
    QString nom;
    int departement_id,manager_id,num_membre;
};

#endif // DEPARTEMENT_H
