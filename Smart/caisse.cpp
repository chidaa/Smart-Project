#include "caisse.h"
#include <QDebug>
Caisse::Caisse()
{
id=0;
type="";
quantite=0;
prix="";
}
Caisse::Caisse(int id,QString type,int quantite, QString prix)
{
  this->id=id;
  this->type=type;
  this->quantite=quantite;
  this->prix=prix;
}
QString Caisse::get_type(){return  type;}
int Caisse::get_id(){return  id;}
QString Caisse::get_prix(){return  prix;}
int Caisse::get_quantite(){return  quantite;}
bool Caisse::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString re= QString::number(quantite);
query.prepare("INSERT INTO caisse (ID, TYPE, QUANTITE, PRIX) "
                    "VALUES (:id, :type, :quantite, :prix )");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":quantite", re);
query.bindValue(":prix", prix);
return    query.exec();
}

QSqlQueryModel * Caisse::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from caisse");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix "));
    return model;
}

bool Caisse::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from caisse where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Caisse::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE caisse SET TYPE=:type,  QUANTITE=:quantite,  PRIX=:prix WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":quantite", res);
    query.bindValue(":prix", prix);
    return    query.exec();



}
QSqlQueryModel * Caisse::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from caisse where(ID LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix "));
        return model;
}
QSqlQueryModel * Caisse:: afficher_trier1()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from caisse ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX "));
        return model;
}
QSqlQueryModel* Caisse::calcul_prix_total(QString ref)
{

            QSqlQueryModel *model=new QSqlQueryModel();
            QSqlQuery q;
            q.prepare("select ID,(Prix*QUANTITE) as prix_total from caisse where ID=:ref");
            q.bindValue(":ref",ref);
            q.exec();
          model->setQuery(q);
          return(model);
}
QSqlQueryModel* Caisse:: calcul_total()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select sum(prix_total) from (select ID,(Prix*QUANTITE) as prix_total from caisse )");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("prix_total"));
  return(model);
}
