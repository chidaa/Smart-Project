#include "abonnemnt_park.h"
#include <QDebug>
Abonnemnt_park::Abonnemnt_park()
{
id_abonnement=0;
nom="";
prenom="";
type_abonnement="";
d_f="";
}
Abonnemnt_park::Abonnemnt_park(int id_abonnement,QString nom,QString prenom,QString d_f,QString type_abonnement)
  {
    this->id_abonnement=id_abonnement;
    this->nom=nom;
    this->prenom=prenom;
    this->d_f=d_f;
    this->type_abonnement=type_abonnement;
  }
bool Abonnemnt_park::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_abonnement);
query.prepare("INSERT INTO abonnement_park (ID_ABONNEMENT, NOM, PRENOM,D_F,TYPE_ABONNEMENT) "
                    "VALUES (:id_abonnement, :nom, :prenom,:d_f,:type_abonnement)");
query.bindValue(":id_abonnement", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":d_f",d_f);
query.bindValue(":type_abonnement", type_abonnement);

return    query.exec();
}
QSqlQueryModel * Abonnemnt_park::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnement_park");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABONNEMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("D_F"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ABONNEMENT"));
    return model;
}

bool Abonnemnt_park::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from abonnement_park where ID_ABONNEMENT = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Abonnemnt_park::modifier(int id_abonnement)
{
    QSqlQuery query;
    QString res= QString::number(id_abonnement);
    query.prepare("UPDATE abonnement_park SET NOM=:nom,PRENOM=:prenom,D_F=:d_f,TYPE_ABONNEMENT=:type_abonnement WHERE ID_ABONNEMENT=:id_abonnement");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":d_f",d_f);
    query.bindValue(":type_abonnement",type_abonnement);
    query.bindValue(":id_abonnement",res);
    return    query.exec();
}
QSqlQueryModel * Abonnemnt_park::afficher_trie()
{QSqlQueryModel* model = new QSqlQueryModel();
 model->setQuery("select * from abonnement_park ORDER BY NOM DESC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABONNEMENT"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("D_F"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ABONNEMENT"));
     return model;
}
QSqlQueryModel * Abonnemnt_park::recherche(const QString &id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from abonnement_park where (ID_ABONNEMENT LIKE '"+id+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABONNEMENT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("D_F"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ABONNEMENT"));
         return model;
}
