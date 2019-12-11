#ifndef LOGIN_H
#define LOGIN_H
#include"abonnemnt_park.h"
#include"ticket.h"
#include"ticket_esp.h"
#include <QDialog>
#include"place.h"
#include"jeu.h"
#include"abonnement_espace.h"
#include <QDialog>
#include "employee.h"
#include "departement.h"
#include "caisse.h"
#include "rayon.h"
#include "commandes.h"
#include "four.h"
#include "client.h"
#include "carte.h"
#include<QDate>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_supprimer_2_clicked();

    void on_ajouter_place_clicked();

    void on_supp_place_clicked();

    void on_modifier_pb_clicked();


    void on_modifier_place_clicked();

    void on_modifier_ticket_clicked();

    void on_ajouter_4_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_ab_esp_clicked();

    void on_pushButton_3_clicked();

    void on_supprimer_3_clicked();

    void on_modifier_ticket_2_clicked();

    void on_Rechercher_clicked();

    void on_Rechercher_2_clicked();

    void on_pushButton_4_clicked();

    void on_supprimer_4_clicked();

    void on_modifier_jeu_clicked();

    void makePlot();

    void on_pb_ajouter_7_clicked();

    void on_pb_supprimer_7_clicked();

    void on_pb_recherche_clicked();

    void on_pb_modifier_6_clicked();

    void on_pushButton_8_clicked();

    void on_pb_ajouter_8_clicked();

    void on_pb_recherche_2_clicked();

    void on_pb_supprimer_8_clicked();

    void on_pb_modifier_7_clicked();

    void on_pb_ajouter_5_clicked();

    void on_calcule_prix_clicked();


    void on_pb_supprimer_5_clicked();

    void on_pb_modifier_4_clicked();

    void on_pb_rechercher_3_clicked();

    void on_pb_ajouter_6_clicked();

    void on_pb_supprimer_6_clicked();

    void on_pb_modifier_5_clicked();

    void on_pb_rechercher_4_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_trier_clicked();

    void on_rechercher_clicked();

    void on_ajouter_2_clicked();

    void on_supprimer_5_clicked();

    void on_validerc_clicked();
    void on_date_2_userDateChanged(const QDate &date);

private:
    Ui::Login *ui;
    Abonnemnt_park tmpabon;
    Ticket tmptick;
    Place tmpplace;
    abonnement_espace tmpesp;
    Ticket_esp tmpticket;
    Jeu tmpjeu;
    Employee tmpemployee;
    departement tmpdep;
    Caisse tmpcaisse;
    Rayon tmprayon;
    Commandes tmpcommandes;
    four tmpfour;
    Client tmpclient;
    Carte tmpcarte;
};

#endif // LOGIN_H
