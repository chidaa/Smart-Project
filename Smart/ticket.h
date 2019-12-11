#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ticket
{
public:
    Ticket();
    Ticket(int,QString,QString);
    int get_id_ticket();
    QString get_type();
    float get_prix();
    bool ajouter_tick();
    QSqlQueryModel * afficher_tick();
    bool supprimer_tick(int);
    bool modifier(int);
    QSqlQueryModel * calcul_prix();
private:
   int ticket_id;
   QString type,prix;
};

#endif // TICKET_H
