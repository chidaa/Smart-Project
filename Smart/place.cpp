#include "place.h"
#include <QDebug>

Place::Place()
{
num=0;
type_p="";
etat="";
}
Place::Place(int num,QString type_p,QString etat)
  {
    this->num=num;
    this->type_p=type_p;
    this->etat=etat;
  }
bool Place::ajouter_place()
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("INSERT INTO parking (NUM,TYPE,ETAT) "
                    "VALUES (:num, :type_p, :etat)");
query.bindValue(":num", res);
query.bindValue(":type_p",type_p);
query.bindValue(":etat",etat);
return    query.exec();
}
QSqlQueryModel * Place::afficher_place()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parking");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

bool Place::supprimer_place(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from parking where NUM = :num ");
query.bindValue(":num", res);
return    query.exec();
}
bool Place:: modifier(int num)
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("UPDATE parking SET TYPE=:type_p,ETAT=:etat WHERE NUM=:num");
    query.bindValue(":type_p",type_p);
    query.bindValue(":etat",etat);
    query.bindValue(":num", res);
    return    query.exec();
}
