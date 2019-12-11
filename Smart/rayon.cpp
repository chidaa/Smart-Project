#include "rayon.h"

#include <QDebug>
Rayon::Rayon()
{
id_3=0;
type_2="";
etat=0;
materiels="";
}
Rayon::Rayon(int id_3,QString type_2,int etat,QString materiels)
{
  this->id_3=id_3;
  this->type_2=type_2;
  this->etat=etat;
  this->materiels=materiels;
}
QString Rayon::get_type_2(){return  type_2;}
int Rayon::get_etat(){return  etat;}
QString Rayon::get_materiels(){return  materiels;}
int Rayon::get_id_3(){return  id_3;}

bool Rayon::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(id_3);
query.prepare("INSERT INTO rayon (ID_3, TYPE_2, ETAT, MATERIELS) "
                    "VALUES (:id_3, :type_2, :etat, :materiels )");
query.bindValue(":id_3", res);
query.bindValue(":type_2", type_2);
query.bindValue(":etat", etat);
query.bindValue(":materiels", materiels);
return    query.exec();
}

QSqlQueryModel * Rayon::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rayon");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Materiels "));
    return model;
}

bool Rayon::supprimer_2(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from rayon where ID_3 = :id_3 ");
query.bindValue(":id_3", res);
return    query.exec();
}
bool Rayon::modifier_2(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE rayon SET TYPE_2=:type_2,  ETAT=:etat,  MATERIELS=:materiels WHERE ID_3=:id_3");
    query.bindValue(":id_3", res);
    query.bindValue(":type_2", type_2);
    query.bindValue(":etat", etat);
    query.bindValue(":materiels", materiels);
    return    query.exec();



}
QSqlQueryModel * Rayon::recherche_2(const QString &id_3)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from rayon where(ID_3 LIKE '"+id_3+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_3"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type_2 "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MATERIELS "));
        return model;
}
QSqlQueryModel * Rayon:: afficher_trier()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from rayon ORDER BY ID_3");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_3"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type_2 "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MATERIELS "));
        return model;
}
