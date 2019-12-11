#include "jeu.h"
#include <QDebug>
Jeu::Jeu()
{
 jeu_id=0;
 nbr_enf=0;
 nbr_tick=0;
 type_jeu="";
}
Jeu::Jeu(int jeu_id,QString type_jeu,int nbr_tick,int nbr_enf)
{
 this->jeu_id=jeu_id;
 this->type_jeu=type_jeu;
 this->nbr_tick=nbr_tick;
 this->nbr_enf=nbr_enf;
}
bool Jeu::ajouter()
{
QSqlQuery query;
QString res= QString::number(jeu_id);
QString nbr_tic= QString::number(nbr_tick);
QString nbr_en= QString::number(nbr_enf);
query.prepare("INSERT INTO jeu (JEU_ID,TYPE_JEU,NUM_TICKET,NUM_ENF) "
                    "VALUES (:jeu_id, :type_jeu, :num_tick,:num_enf)");
query.bindValue(":jeu_id", res);
query.bindValue("::type_jeu", type_jeu);
query.bindValue(":num_tick", nbr_tic);
query.bindValue(":num_enf",nbr_en);

return    query.exec();
}
QSqlQueryModel * Jeu::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from jeu");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("JEU_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_JEU "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_TICKET"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_ENF"));
    return model;
}

bool Jeu::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from jeu where JEU_ID= :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Jeu::modifier(int jeu_id)
{
    QSqlQuery query;
    QString res= QString::number(jeu_id);
    QString nbr_tic= QString::number(nbr_tick);
    QString nbr_en= QString::number(nbr_enf);
    query.prepare("UPDATE jeu SET TYPE_JEU=:type_jeu,NUM_TICKET=:num_tick,NUM_ENF=:num_enf WHERE JEU_ID=:jeu_id");
    query.bindValue(":jeu_id", res);
    query.bindValue(":type_jeu", type_jeu);
    query.bindValue(":num_tick", nbr_tic);
    query.bindValue(":num_enf",nbr_en);
    return    query.exec();
}
QSqlQueryModel * Jeu::afficher_trie()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from jeu ORDER BY JEU_ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("JEU_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_JEU "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_TICKET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_ENF"));
        return model;
}
QSqlQueryModel * Jeu::recherche(const QString &id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from jeu where (JEU_ID LIKE '"+id+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("JEU_ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_JEU "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_TICKET"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_ENF"));
         return model;
}
