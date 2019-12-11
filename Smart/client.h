#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{public:
    Client();
    Client(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * recherche(const QString &id);

private:
    QString nom,prenom;
    int id;
};

#endif // CLIENT_H
