#include "four.h"
#include <QDebug>
four::four()
{
numtel=0;
idfourn=0;
catprod="";
nomfourn="";
prenomfourn="";
}
four::four(int numtel,int idfourn, QString catprod,QString nomfourn,QString prenomfourn)
{
  this->numtel=numtel;
  this->idfourn=idfourn;
  this->catprod=catprod;
    this->nomfourn=nomfourn;
    this->prenomfourn=prenomfourn;
}

int four::get_numtel(){return  numtel;}
int four::get_idfourn(){return  idfourn;}
QString four::get_catprod(){return  catprod;}
QString four::get_nomfourn(){return  nomfourn;}
QString four::get_prenomfourn(){return  prenomfourn;}

bool four::ajouter_3()
{
QSqlQuery query;
QString res= QString::number(numtel);
QString re=QString::number(idfourn);
query.prepare("INSERT INTO four  (NUMTEL,IDFOURN,CATPROD,NOMFOURN,PRENOMFOURN) "
                    "VALUES (:numtel,:idfourn,:catprod,:nomfourn,:prenomfourn)");
query.bindValue(":numtel", res);
query.bindValue(":idfourn", re);
query.bindValue(":catprod", catprod);
query.bindValue(":nomfourn", nomfourn);
query.bindValue(":prenomfourn", prenomfourn);
return    query.exec();
}

QSqlQueryModel * four::afficher_2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from four");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFOURN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMTEL"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMFOURN "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOMFOURN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CATPROD"));
    return model;
}

bool four::supprimer_2(int idfourn)
{
QSqlQuery query;
QString res= QString::number(idfourn);
query.prepare("Delete from four where IDFOURN = :idfourn ");
query.bindValue(":idfourn", res);
return    query.exec();
}
bool four::modifier_2(int idfourn)
{
    QSqlQuery query;
   QString res= QString::number(idfourn);
    QString rese=QString::number(numtel);
   query.prepare("UPDATE FOUR SET CATPROD=:catprod,NUMTEL=:numtel, NOMFOURN=:nomfourn, PRENOMFOURN=:prenomfourn WHERE IDFOURN=:idfourn");
   query.bindValue(":catprod", catprod);
   query.bindValue(":idfourn", res);
   query.bindValue(":numtel", rese);
   query.bindValue(":nomfourn", nomfourn);
   query.bindValue(":prenomfourn", prenomfourn);
   return  query.exec();
}
QSqlQueryModel * four::rechercher(const QString &idfourn)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from four where(IDFOURN LIKE '"+idfourn+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMTEL "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nomfourn"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenomfourn"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catprog"));


        return model;
}
QSqlQueryModel * four:: afficher_trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from four ORDER BY IDFOURN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMTEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMFOURN "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOMFOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CATPROD"));
        return model;
}
