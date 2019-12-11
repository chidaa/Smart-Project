#include "departement.h"
#include <QDebug>
departement::departement()
{
    departement_id=0;
    nom="";
    manager_id=0;
    num_membre=0;

}

departement::departement(int departement_id,QString departement_name,int manager_id,int num_membre)
{
  this->departement_id=departement_id;
  this->nom=departement_name;
  this->manager_id=manager_id;
  this->num_membre=num_membre;
}
QString departement::get_nom(){return nom;}
int departement::get_departement_id(){return  departement_id;}
int departement::get_manager_id(){return  manager_id;}
int departement::get_num_membre(){return  num_membre;}

bool departement::ajouter()
{
QSqlQuery query;
QString res= QString::number(departement_id);
query.prepare("INSERT INTO dep (ID, NOM,NUM_MEMBRE, MANAGER_ID) "
                    "VALUES (:departement_id,:nom,:manager_id,:num_membre)");
query.bindValue(":departement_id", departement_id);
query.bindValue(":nom", nom);
query.bindValue(":manager_id", manager_id);
query.bindValue(":num_membre", num_membre);

return    query.exec();
}
QSqlQueryModel * departement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from dep");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MANAGER_NAME"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_MEMBRE"));

    return model;
}
bool departement::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from dep where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool departement::modifier(int departement_id)
{
    QSqlQuery query;
   QString res= QString::number(departement_id);
   QString rese=QString::number(num_membre);
   query.prepare("UPDATE DEP SET ID=:departement_id,NOM=:nom,NUM_MEMBRE=:num_membre,MANAGER_ID=:manager_id WHERE ID=:departement_id");
   query.bindValue(":departement_id", res);
   query.bindValue(":nom", nom);
   query.bindValue(":num_membre", num_membre);
   query.bindValue(":manager_id", manager_id);

    return  query.exec();
}
QSqlQueryModel *departement::rechercher_personnel(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from dep where(ID LIKE '"+id+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("MANAGER_NAME"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_MEMBRE"));
    return model;
}

