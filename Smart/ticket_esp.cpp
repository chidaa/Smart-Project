#include "ticket_esp.h"
#include <QDebug>
Ticket_esp::Ticket_esp()
{
ticket_id=0;
type="";
prix="";
date="";
}
Ticket_esp::Ticket_esp(int ticket_id,QString type,QString prix,QString date)
  {
    this->ticket_id=ticket_id;
    this->type=type;
    this->prix=prix;
    this->date=date;
  }
bool Ticket_esp::ajouter_tick()
{
QSqlQuery query;
QString res= QString::number(ticket_id);
query.prepare("INSERT INTO ticket_esp (TICKET_ID,TYPE,PRIX,DATE_FIN) "
                    "VALUES (:ticket_id, :type, :prix ,:date)");
query.bindValue(":ticket_id", res);
query.bindValue(":type",type);
query.bindValue(":prix",prix);
query.bindValue(":date",date);
return    query.exec();
}
QSqlQueryModel * Ticket_esp::afficher_tick()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ticket_esp");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TICKET_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
    return model;
}

bool Ticket_esp::supprimer_tick(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from ticket_esp where TICKET_ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Ticket_esp::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE ticket_esp SET TYPE = :type,PRIX = :prix,DATE_FIN=:date where TICKET_ID = :id");
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    query.bindValue(":date",date);
    query.bindValue(":id", res);
    return    query.exec();
}
QSqlQueryModel * Ticket_esp:: calcul_prix()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select sum(prix) from ticket_esp");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prix_totale"));
    return model;
}
