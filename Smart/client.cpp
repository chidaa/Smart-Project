#include "client.h"
#include <QDebug>
Client::Client()
{
id=0;
nom="";
prenom="";
}
Client::Client(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_id(){return  id;}

bool Client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client (ID, NOM, PRENOM) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}
bool Client::modifier(int id, QString nom, QString prenom)
{QSqlQuery query;
  QString res= QString::number(id);
   query.prepare("UPDATE client "
                 "SET ID =:id, NOM=:nom,PRENOM=:prenom "
                 "WHERE ID=:id ") ;
   query.bindValue(":id", res);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);

   return    query.exec();

}

bool Client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * Client::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from client where(ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
        return model;
}
QSqlQueryModel * Client::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by ID");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));


    return model;
}
