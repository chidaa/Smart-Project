#include "ticket.h"
#include <QDebug>
Ticket::Ticket()
{
ticket_id=0;
type="";
prix="";
}
Ticket::Ticket(int ticket_id,QString type,QString prix)
  {
    this->ticket_id=ticket_id;
    this->type=type;
    this->prix=prix;
  }
bool Ticket::ajouter_tick()
{
QSqlQuery query;
QString res= QString::number(ticket_id);
query.prepare("INSERT INTO ticket_parking (TICKET_ID,TYPE,PRIX) "
                    "VALUES (:ticket_id, :type, :prix)");
query.bindValue(":ticket_id", res);
query.bindValue(":type",type);
query.bindValue(":prix",prix);
return    query.exec();
}
QSqlQueryModel * Ticket::afficher_tick()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ticket_parking");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TICKET_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

bool Ticket::supprimer_tick(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from ticket_parking where TICKET_ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Ticket::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE ticket_parking SET TYPE = :type,PRIX = :prix where TICKET_ID = :id");
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    query.bindValue(":id", res);
    return    query.exec();
}
QSqlQueryModel * Ticket:: calcul_prix()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select sum(prix) from ticket_parking");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prix_totale"));
    return model;
}
