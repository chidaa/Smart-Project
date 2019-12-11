#include "commandes.h"
#include <QDebug>
Commandes::Commandes()
{
idcom=0;
idfourn=0;
catprod="";
}
Commandes::Commandes(QString catprod,int idfourn,int idcom)
{
  this->idcom=idcom;
  this->idfourn=idfourn;
  this->catprod=catprod;
}
QString Commandes::get_catprod(){return  catprod;}
int Commandes::get_idcom(){return  idcom;}
int Commandes::get_idfourn(){return  idfourn;}


bool Commandes::ajouter()
{
QSqlQuery query;
QString res= QString::number(idcom);
QString re=QString::number(idfourn);
query.prepare("INSERT INTO Commandes (CATPROD,IFDOURN,IDCOM) "
                    "VALUES (:catprod,:idfourn,:idcom)");
query.bindValue(":catprod", catprod);
query.bindValue(":idfourn", re);
query.bindValue(":idcom", res);
return    query.exec();
}

QSqlQueryModel * Commandes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commandes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CATPROD"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("IFDOURN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDCOM "));
    return model;
}

bool Commandes::supprimer(int idcom)
{
QSqlQuery query;
QString res= QString::number(idcom);
query.prepare("Delete from commandes where IDCOM = :idcom ");
query.bindValue(":idcom", res);
return    query.exec();
}
bool Commandes::modifier(int idcom)
{
    QSqlQuery query;
   QString res= QString::number(idfourn);
    QString rese=QString::number(idcom);
   query.prepare("UPDATE COMMANDES SET CATPROD=:catprod,IFDOURN=:idfourn WHERE IDCOM=:idcom");
   query.bindValue(":catprod", catprod);
   query.bindValue(":idfourn", res);
   query.bindValue(":idcom", rese);
   return  query.exec();
}
QSqlQueryModel * Commandes::rechercher(const QString &idcom)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from commandes where(IDCOM LIKE '"+idcom+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDFOURN "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CATPROD"));

        return model;
}



QSqlQueryModel * Commandes::afficher_trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from four ORDER BY IDCOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDFOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATPROD"));
        return model;
}


