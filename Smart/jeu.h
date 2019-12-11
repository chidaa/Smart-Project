#ifndef JEU_H
#define JEU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Jeu
{
public:
    Jeu();
    Jeu(int,QString,int,int);
    int get_jeu_id(){return jeu_id;}
    QString get_type_jeu(){return type_jeu;}
    int get_nombre_tick(){return nbr_tick;}
    int get_nombre_enf(){return nbr_enf;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_trie();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * recherche(const QString&);
private:
    QString type_jeu;
    int jeu_id,nbr_tick,nbr_enf;
};

#endif // JEU_H
