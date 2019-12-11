#include "employee.h"
#include <QDebug>
Employee::Employee()
{
id=0;
nom="";
prenom="";
age=0;
id_dep=0;
cin=0;
numtel=0;

}
Employee::Employee(int id,QString nom,QString prenom,int id_dep,int age,int cin,int numtel)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->id_dep=id_dep;
  this->age=age;
  this->cin=cin;
  this->numtel=numtel;
}
QString Employee::get_nom(){return  nom;}
QString Employee::get_prenom(){return prenom;}
int Employee::get_id(){return  id;}
int Employee::get_iddep(){return  id_dep;}
int Employee::get_age(){return  age;}
int Employee::get_cin(){return  cin;}
int Employee::get_numtel(){return  numtel;}

bool Employee::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employee (ID, ID_DEP, CIN, AGE, NUM_TEL, NOM, PRENOM) "
                    "VALUES (:id,:id_dep,:cin,:age,:numtel,:nom,:prenom)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":id", id);
query.bindValue(":id_dep", id_dep);
query.bindValue(":cin", cin);
query.bindValue(":age", age);
query.bindValue(":numtel", numtel);


return    query.exec();
}

QSqlQueryModel * Employee::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employee");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_DEP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRENOM"));
    return model;
}

bool Employee::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from employee where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Employee::modifier(int id)
{
    QSqlQuery query;
   QString res= QString::number(id);
   query.prepare("UPDATE EMPLOYEE SET ID=:id,ID_DEP=:id_dep,CIN=:cin,AGE=:age,NUM_TEL=:numtel,NOM=:nom,PRENOM=:prenom WHERE ID=:id");
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":id", id);
   query.bindValue(":id_dep", id_dep);
   query.bindValue(":cin", cin);
   query.bindValue(":age", age);
   query.bindValue(":numtel", numtel);

    return  query.exec();
}
QSqlQueryModel *Employee::afficher_personnel_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from employee ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    return model;
}

QSqlQueryModel *Employee::rechercher_personnel(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from employee where(ID LIKE '"+id+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    return model;
}
