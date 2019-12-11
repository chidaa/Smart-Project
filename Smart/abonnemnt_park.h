#ifndef ABONNEMNT_PARK_H
#define ABONNEMNT_PARK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
class Abonnemnt_park
{
public:
    Abonnemnt_park();
    Abonnemnt_park(int,QString,QString,QString,QString);
    QString get_nom(){return nom;}
    QString get_type_abonnement(){return type_abonnement;}
    QString get_prenom(){return prenom;}
    int get_id_abonnemet(){return id_abonnement;}
    QString get_d_f(){return d_f;}
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher_trie();
        bool supprimer(int);
        bool modifier(int);
        QSqlQueryModel * recherche(const QString&);
    private:
        QString nom,prenom,type_abonnement,d_f;
        int id_abonnement;
};

#endif // ABONNEMNT_PARK_H
