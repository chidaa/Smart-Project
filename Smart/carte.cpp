#include "carte.h"
#include <QDebug>
Carte::Carte()
{
 point=0;
id=0;
datee="";
}
Carte::Carte(int point,int id,QString datee)
{
    this->point=point;
  this->id=id;
  this->datee=datee;

}
QString Carte::get_datee(){return datee;}
int Carte::get_id(){return  id;}
int Carte::get_point(){return  point;}

bool Carte::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO carte (ID, point, datee) "
                    "VALUES (:id, :point, :datee)");
query.bindValue(":id", res);
query.bindValue(":point", point);
query.bindValue(":datee", datee);

return    query.exec();
}

QSqlQueryModel * Carte::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("point "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    return model;
}

bool Carte::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Carte::modifier(int id, QString datee,int point)
{QSqlQuery query;
  QString res= QString::number(id);
   query.prepare("UPDATE carte "
                 "SET ID =:id, DATEE=:datee, POINT=:point "
                 "WHERE ID=:id ") ;
   query.bindValue(":id", res);
   query.bindValue(":point", point);
   query.bindValue(":datee", datee);

   return    query.exec();

}
