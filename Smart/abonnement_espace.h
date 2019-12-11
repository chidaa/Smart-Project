#ifndef ABONNEMENT_ESPACE_H
#define ABONNEMENT_ESPACE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class abonnement_espace
{
public:
    abonnement_espace();
    abonnement_espace(int,QString,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_type_abon();
    QString get_df(){return d_f;}
    void setdate(QString date)
    {d_f=date;}
    QString generatedate(QString j,QString m,QString a)
    {if(j.length()==1)
    {j='0'+j;}
        if(m.length()==1)
            {m='0'+m;}
        return  j+"-"+m+"-"+a;
        }
    int get_id_abon();
    int get_cin();
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher_trie();
        bool supprimer(int);
        bool modifier(int);
        QSqlQueryModel * recherche(const QString&);
        QVector<double> statistique();
    private:
        QString nom,prenom,type_abon,d_f;
        int id_abon,cin;
};

#endif // ABONNEMENT_ESPACE_H
