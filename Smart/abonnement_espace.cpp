#include "abonnement_espace.h"

abonnement_espace::abonnement_espace()
{
 nom="";
 prenom="";
 type_abon="";
 id_abon=0;
 cin=0;
 d_f="";
}
abonnement_espace::abonnement_espace(int id_abon,QString nom,QString prenom,QString type_abon,QString d_f,int cin)
{
    this->id_abon=id_abon;
    this->nom=nom;
    this->prenom=prenom;
    this->type_abon=type_abon;
    this->d_f=d_f;
    this->cin=cin;
}
bool abonnement_espace::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_abon);
QString re= QString::number(cin);
query.prepare("INSERT INTO abonnement_espace (ID_ABON, NOM, PRENOM,TYPE_ABON,DATE_FIN,CIN_PARENT) "
                    "VALUES (:id_abon, :nom, :prenom,:type_abon,:d_f,:cin)");
query.bindValue(":id_abon", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":d_f",d_f);
query.bindValue(":type_abon", type_abon);
query.bindValue(":cin", re);
return    query.exec();
}
QSqlQueryModel * abonnement_espace::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnement_espace");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABONNEMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_ABONNEMENT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN_PARENT"));
    return model;
}

bool abonnement_espace::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from abonnement_espace where ID_ABON = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool abonnement_espace::modifier(int id_abonnement)
{
    QSqlQuery query;
    QString res= QString::number(id_abonnement);
    QString re= QString::number(cin);
    query.prepare("UPDATE abonnement_espace SET NOM=:nom,PRENOM=:prenom,TYPE_ABON=:type_abon,DATE_FIN=:d_f,CIN_PARENT=:cin WHERE ID_ABON=:id_abonnement");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":d_f",d_f);
    query.bindValue(":type_abon",type_abon);
    query.bindValue(":cin",re);
    query.bindValue(":id_abonnement",res);
    return    query.exec();
}
QSqlQueryModel * abonnement_espace::afficher_trie()
{QSqlQueryModel* model = new QSqlQueryModel();
 model->setQuery("select * from abonnement_espace ORDER BY DATE_FIN DESC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABON"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ABON"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN_PARENT"));
     return model;
}
QSqlQueryModel * abonnement_espace:: recherche(const QString& id)
{QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("select * from abonnement_espace where (ID_ABON LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ABON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ABON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN_PARENT"));
        return model;

}
QVector<double> abonnement_espace:: statistique()
{
    QSqlQuery q;
    QVector<double> stat(12);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    stat[6]=0;
    stat[7]=0;
    stat[8]=0;
    stat[9]=0;
    stat[10]=0;
    stat[11]=0;
    q.prepare("SELECT * FROM abonnement_espace WHERE 01-01-2019=DATE_FIN and DATE_FIN<=31-01-2019");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }

    q.prepare("SELECT * FROM abonnement_espace WHERE 31-01-2019<DATE_FIN and DATE_FIN<=31-02-2019");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

   q.prepare("SELECT * FROM abonnement_espace WHERE 31-02-2019<DATE_FIN and DATE_FIN<=31-03-2019");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }

   q.prepare("SELECT * FROM abonnement_espace WHERE 31-03-2019<DATE_FIN and DATE_FIN<=31-04-2019");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }

    q.prepare("SELECT * FROM abonnement_espace WHERE 31-04-2019<DATE_FIN and DATE_FIN<=31-05-2019");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-05-2019<DATE_FIN and DATE_FIN<=31-06-2019");
    q.exec();
    while (q.next())
    {
        stat[5]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-06-2019<DATE_FIN and DATE_FIN<=31-07-2019");
    q.exec();
    while (q.next())
    {
        stat[6]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-07-2019<DATE_FIN and DATE_FIN<=31-08-2019");
    q.exec();
    while (q.next())
    {
        stat[7]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-08-2019<DATE_FIN and DATE_FIN<=31-9-2019");
    q.exec();
    while (q.next())
    {
        stat[8]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-9-2019<DATE_FIN and DATE_FIN<=31-10-2019");
    q.exec();
    while (q.next())
    {
        stat[9]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-10-2019<DATE_FIN and DATE_FIN<=31-11-2019");
    q.exec();
    while (q.next())
    {
        stat[10]++;
    }
    q.prepare("SELECT * FROM abonnement_espace WHERE 31-11-2019<DATE_FIN and DATE_FIN<=31-12-2019");
    q.exec();
    while (q.next())
    {
        stat[11]++;
    }
    return stat;
}
