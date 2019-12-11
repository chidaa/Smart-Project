#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
          ui->tabcaisse_6->setModel(tmpcaisse.afficher_trier1());
    ui->tabclient->setModel(tmpclient.afficher());
    ui->tabcarte->setModel(tmpcarte.afficher());
    ui->tab_abon->setModel(tmpabon.afficher());//refresh
    ui->tab_tri->setModel(tmpabon.afficher_trie());
    ui->table_tick->setModel(tmptick.afficher_tick());
    ui->table_tick_5->setModel(tmptick.calcul_prix());
    ui->table_place->setModel(tmpplace.afficher_place());
    ui->tab_abon_2->setModel(tmpesp.afficher());//refresh
    ui->tab_tri_2->setModel(tmpesp.afficher_trie());
    ui->table_tick_2->setModel(tmpticket.afficher_tick());
    ui->table_tick_4->setModel(tmpticket.calcul_prix());
    ui->tabemployee->setModel(tmpemployee.afficher());
    ui->tabemployee_2->setModel(tmpdep.afficher());
    Login::makePlot();
    ui->tabcaisse_2->setModel(tmpcaisse.afficher());//refresh
    ui->tabrayon->setModel(tmprayon.afficher());
         ui->tabrayon_2->setModel(tmprayon.afficher_trier());
    ui->tabcommandes->setModel(tmpcommandes.afficher());//refresh
    ui->tabcommandes_3->setModel(tmpfour.afficher_2());//refresh
    ui->tabcommandes_5->setModel(tmpfour.afficher_trier());//refresh
}

Login::~Login()
{
    delete ui;
}
void Login::on_date_2_userDateChanged(const QDate &date)
{
    QString d;
    d=tmpesp.generatedate(QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
    tmpesp.setdate(d);
}
void Login::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString date=ui->lineEdit_date->text();
    QString type=ui->lineEdit_type->text();
  Abonnemnt_park abon(id,nom,prenom,date,type);
  bool test=abon.ajouter();
  if(test)
{ui->tab_abon->setModel(tmpabon.afficher());//refresh
 ui->tab_tri->setModel(tmpabon.afficher_trie());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnement"),
                  QObject::tr("Abonnement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
void Login::on_supprimer_clicked()
{
    int id = ui->lineEdit_idsupp->text().toInt();
    bool test=tmpabon.supprimer(id);
    if(test)
    {ui->tab_abon->setModel(tmpabon.afficher());
      ui->tab_tri->setModel(tmpabon.afficher_trie());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                    QObject::tr("Abonnement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonnement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pushButton_clicked()//ajouter ticket
{
    int id = ui->lineEdit_idtick->text().toInt();
    QString type= ui->lineEdit_typetick->text();
    QString prix= ui->lineEdit_prix->text();
    Ticket tick(id,type,prix);
  bool test=tick.ajouter_tick();
  if(test)
{ui->table_tick->setModel(tmptick.afficher_tick());//refresh
 ui->table_tick_5->setModel(tmptick.calcul_prix());
QMessageBox::information(nullptr, QObject::tr("Ajouter une ticket"),
                  QObject::tr("Ticket ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_supprimer_2_clicked()//supp ticket
{
    int id = ui->lineEdit_supptick->text().toInt();
    bool test=tmptick.supprimer_tick(id);
    if(test)
    {ui->table_tick->setModel(tmptick.afficher_tick());//refresh
     ui->table_tick_5->setModel(tmptick.calcul_prix());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Ticket supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Login::on_ajouter_place_clicked()
{
    int num = ui->lineEdit_num->text().toInt();
    QString type= ui->lineEdit_typeplace->text();
    QString etat= ui->lineEdit_etatplace->text();
  Place place(num,type,etat);
  bool test=place.ajouter_place();
  if(test)
{ui->table_place->setModel(tmpplace.afficher_place());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                  QObject::tr("Place ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void Login::on_supp_place_clicked()
{
    int num = ui->lineEdit_numsupp->text().toInt();
    bool test=tmpplace.supprimer_place(num);
    if(test)
    {ui->table_place->setModel(tmpplace.afficher_place());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("Place supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_modifier_pb_clicked()
{
    int id = ui->lineEdit_idmod->text().toInt();
    QString nom= ui->lineEdit_nommod->text();
    QString prenom= ui->lineEdit_premod->text();
    QString date=ui->lineEdit_dfmod->text();
    QString type=ui->lineEdit_typemod->text();
   Abonnemnt_park abon(id,nom,prenom,date,type);
  bool test=abon.modifier(id);
  if(test)
{ui->tab_abon->setModel(tmpabon.afficher());//refresh
 ui->tab_tri->setModel(tmpabon.afficher_trie());
QMessageBox::information(nullptr, QObject::tr("Modifier un abonnement"),
                  QObject::tr("Abonnement modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_modifier_place_clicked()
{
    int num = ui->lineEdit_num_2->text().toInt();
    QString type= ui->lineEdit_typeplace_2->text();
    QString etat= ui->lineEdit_etatplace_2->text();
  Place place(num,type,etat);
  bool test=place.modifier(num);
  if(test)
{ui->table_place->setModel(tmpplace.afficher_place());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une place"),
                  QObject::tr("Place modifer.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une place"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_modifier_ticket_clicked()
{
    int id = ui->lineEdit_idtick_2->text().toInt();
    QString type= ui->lineEdit_typetick_2->text();
    QString prix= ui->lineEdit_prix_2->text();
    Ticket tick(id,type,prix);
  bool test=tick.modifier(id);
  if(test)
{ui->table_tick->setModel(tmptick.afficher_tick());
ui->table_tick_5->setModel(tmptick.calcul_prix());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une ticket"),
                  QObject::tr("Ticket modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_ajouter_4_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString type=ui->lineEdit_type_4->text();
    int cin=ui->lineEdit_cin->text().toInt();
  abonnement_espace abon(id,nom,prenom,type,tmpesp.get_df(),cin);
  bool test=abon.ajouter();
  if(test)
{ui->tab_abon_2->setModel(tmpesp.afficher());//refresh
 ui->tab_tri_2->setModel(tmpesp.afficher_trie());//refresh
 Login::makePlot();
QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnement"),
                  QObject::tr("Abonnement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pushButton_2_clicked()//supp abo espace enfant
{
    int id = ui->lineEdit_supp1->text().toInt();
    bool test=tmpesp.supprimer(id);
    if(test)
    {ui->tab_abon_2->setModel(tmpesp.afficher());
      ui->tab_tri_2->setModel(tmpesp.afficher_trie());//refresh
      Login::makePlot();
        QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                    QObject::tr("Abonnement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonnement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_modifier_ab_esp_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
    QString type=ui->lineEdit_type_5->text();
    int cin=ui->lineEdit_cin_2->text().toInt();
  abonnement_espace abon(id,nom,prenom,type,tmpesp.get_df(),cin);
  bool test=abon.modifier(id);
  if(test)
{ui->tab_abon_2->setModel(tmpesp.afficher());//refresh
 ui->tab_tri_2->setModel(tmpesp.afficher_trie());//refresh
 Login::makePlot();
QMessageBox::information(nullptr, QObject::tr("Modifier un abonnement"),
                  QObject::tr("Abonnement modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pushButton_3_clicked()//ajout tiket esp
{
    int id = ui->lineEdit_idtick_3->text().toInt();
    QString type= ui->lineEdit_typetick_3->text();
    QString prix= ui->lineEdit_prix_3->text();
    QString date= ui->lineEdit_date_2->text();
    Ticket_esp tick(id,type,prix,date);
  bool test=tick.ajouter_tick();
  if(test)
{ui->table_tick_2->setModel(tmpticket.afficher_tick());
 ui->table_tick_4->setModel(tmpticket.calcul_prix());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une ticket"),
                  QObject::tr("Ticket ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_supprimer_3_clicked()
{
    int id = ui->lineEdit_supptick_2->text().toInt();
    bool test=tmpticket.supprimer_tick(id);
    if(test)
    {ui->table_tick_2->setModel(tmpticket.afficher_tick());//refresh
         ui->table_tick_4->setModel(tmpticket.calcul_prix());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Ticket supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_modifier_ticket_2_clicked()
{
    int id = ui->lineEdit_idtick_4->text().toInt();
    QString type= ui->lineEdit_typetick_4->text();
    QString prix= ui->lineEdit_prix_4->text();
    QString date= ui->lineEdit_datef->text();
    Ticket_esp tick(id,type,prix,date);
  bool test=tick.modifier(id);
  if(test)
{ui->table_tick_2->setModel(tmpticket.afficher_tick());//refresh
 ui->table_tick_4->setModel(tmpticket.calcul_prix());
QMessageBox::information(nullptr, QObject::tr("Modifier une ticket"),
                  QObject::tr("Ticket modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_Rechercher_clicked()
{
    QString id=ui->lineEdit_idrech->text();
    ui->tab_ab_rech->setModel(tmpesp.recherche(id));
}

void Login::on_Rechercher_2_clicked()
{
    QString id=ui->lineEdit_idrech_2->text();
    ui->tab_ab_rech_2->setModel(tmpabon.recherche(id));
}

void Login::on_pushButton_4_clicked()//ajouter_jeu
{
    int id = ui->lineEdit_idjeu->text().toInt();
    QString type= ui->lineEdit_typejeu->text();
    int nb_t= ui->lineEdit_ntic->text().toInt();
    int nb_e=ui->lineEdit_nenf->text().toInt();
    Jeu jeu(id,type,nb_t,nb_e);
  bool test=jeu.ajouter();
  if(test)
{ui->table_tick_3->setModel(tmpjeu.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un jeu"),
                  QObject::tr("Jeu ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jeu"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_supprimer_4_clicked()
{
    int id = ui->lineEdit_supptick_3->text().toInt();
    bool test=tmpjeu.supprimer(id);
    if(test)
    {ui->table_tick_3->setModel(tmpjeu.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un jeu"),
                    QObject::tr("Jeu supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Jeu"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_modifier_jeu_clicked()
{
    int id = ui->lineEdit_idjeu_2->text().toInt();
    QString type= ui->lineEdit_typejeu_2->text();
    int nb_t= ui->lineEdit_ntic_2->text().toInt();
    int nb_e=ui->lineEdit_nenf_2->text().toInt();
    Jeu jeu(id,type,nb_t,nb_e);
  bool test=jeu.modifier(id);
  if(test)
{ui->table_tick_3->setModel(tmpjeu.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un jeu"),
                  QObject::tr("Jeu modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un jeu"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
void Login::makePlot()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    //QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
   // regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
   // nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
   // regen->setStackingGap(1);
   // nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Nombre des abonnements");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    /*nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));*/
    // stack bars on top of each other:
   // nuclear->moveAbove(fossil);
   // regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7<<8<<9<<10<<11<<12;
    labels << "1.1" << "2.1" << "3.1" << "4.1" << "5.1" << "6.1" << "7.1"<< "8.1" << "9.1" << "10.1" << "11.1" << "12.1";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 7);
    ui->customPlot->xAxis->setRange(0, 14);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Nombre des abonnement \n par % date fin(2019)");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData=tmpesp.statistique();
    fossil->setData(ticks, fossilData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}




//sami




void Login::on_pb_ajouter_7_clicked()
{
    int id = ui->lineEdit_id_10->text().toInt();
    QString nom= ui->lineEdit_nom_5->text();
    QString prenom= ui->lineEdit_prenom_5->text();
    int id_dep = ui->lineEdit_id_dep->text().toInt();
    int age = ui->lineEdit_age->text().toInt();
    int cin = ui->lineEdit_cin_3->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();

  Employee e(id,nom,prenom,id_dep,age,cin,numtel);
  bool test=e.ajouter();
  if(test)
{ui->tabemployee->setModel(tmpemployee.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("employee ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un emp"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_pb_supprimer_7_clicked()
{
int id = ui->lineEdit_id_12->text().toInt();
bool test=tmpemployee.supprimer(id);
if(test)
{ui->tabemployee->setModel(tmpemployee.afficher());//refresh
    /*ui->tableView->setModel(tmpemployee.afficher_personnel_trier());*/
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                QObject::tr("Employee supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_pb_recherche_clicked()
    {
        QString id = ui->lineEdit_id_11->text();
        ui->tableView_2->setModel(tmpemployee.rechercher_personnel(id));
        }

void Login::on_pb_modifier_6_clicked()
{
    {
        int id = ui->lineEdit_id_13->text().toInt();
        QString nom= ui->lineEdit_nom_6->text();
        QString prenom= ui->lineEdit_prenom_6->text();
        int id_dep = ui->lineEdit_id_dep_3->text().toInt();
        int age = ui->lineEdit_age_3->text().toInt();
        int cin = ui->lineEdit_cin_4->text().toInt();
        int numtel = ui->lineEdit_numtel_3->text().toInt();
        Employee e(id,nom,prenom,id_dep,age,cin,numtel);
      bool test=e.modifier(id);
      if(test)
    {ui->tabemployee->setModel(tmpemployee.afficher());
    /* ui->tableView->setModel(tmpemployee.afficher_personnel_trier())*/ //refresh
    QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                      QObject::tr("modifier ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void Login::on_pushButton_8_clicked()
{
    ui->tabemployee->setModel(tmpemployee.afficher_personnel_trier());
}

void Login::on_pb_ajouter_8_clicked()
{
        int departement_id = ui->lineEdit_id_14->text().toInt();
        QString departement_name= ui->lineEdit_noom->text();
        int manager_id = ui->lineEdit_manager->text().toInt();
        int num_membre = ui->lineEdit_location->text().toInt();

      departement d(departement_id,departement_name,manager_id,num_membre);
      bool test=d.ajouter();
      if(test)
    {ui->tabemployee_2->setModel(tmpdep.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("departement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un emp"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}




void Login::on_pb_recherche_2_clicked()
{
    QString id = ui->lineEdit_id_15->text();
    ui->tableView_3->setModel(tmpdep.rechercher_personnel(id));
    ui->tabemployee_2->setModel(tmpdep.afficher());
}

void Login::on_pb_supprimer_8_clicked()
{
    int id = ui->lineEdit_id_16->text().toInt();
    bool test=tmpdep.supprimer(id);
    if(test)
    {ui->tabemployee_2->setModel(tmpdep.afficher());//refresh
        /*ui->tableView->setModel(tmpemployee.afficher_personnel_trier());*/
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pb_modifier_7_clicked()
{
    int departement_id = ui->lineEdit_id_17->text().toInt();
    QString departement_name= ui->lineEdit_age_4->text();
    int manager_id = ui->lineEdit_nom_7->text().toInt();
    int num_membre = ui->lineEdit_numtel_4->text().toInt();
    departement d(departement_id,departement_name,manager_id,num_membre);
    bool test=d.modifier(departement_id);
  if(test)
{ui->tabemployee_2->setModel(tmpdep.afficher());
/* ui->tableView->setModel(tmpemployee.afficher_personnel_trier())*/ //refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Login::on_pb_ajouter_5_clicked()
{
    int id = ui->lineEdit_id_6->text().toInt();
    QString type= ui->lineEdit_type_2->text();
    int quantite = ui->lineEdit_quantite->text().toInt();
    QString prix= ui->lineEdit_prix_5->text();
  Caisse c(id,type,quantite,prix);
  bool test=c.ajouter();
  if(test)
{ui->tabcaisse_2->setModel(tmpcaisse.afficher());//refresh
 ui->tabcaisse_6->setModel(tmpcaisse.afficher_trier1());
 ui->prixtot->setModel(tmpcaisse.calcul_total());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}

void Login::on_calcule_prix_clicked()
{
    Caisse f;
    QString id=ui->lineEdit_calcule->text();
    ui->calculetab->setModel(f.calcul_prix_total(id));
}

void Login::on_pb_supprimer_5_clicked()
{
    int id = ui->lineEdit_id_7->text().toInt();
    bool test=tmpcaisse.supprimer(id);
    if(test)
    {ui->tabcaisse_2->setModel(tmpcaisse.afficher());
        ui->prixtot->setModel(tmpcaisse.calcul_total());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_modifier_4_clicked()
{
    int id = ui->lineEdit_idmod_2->text().toInt();
    QString type=ui->lineEdit_typemod_2->text();
    int quantite = ui->lineEdit_quantitemod->text().toInt();
   QString prix=ui->lineEdit_prixmod->text();
   Caisse c(id,type,quantite,prix);
  bool test=c.modifier(id);
  if(test)
{ui->tabcaisse_2->setModel(tmpcaisse.afficher());//refresh
      ui->tabcaisse_6->setModel(tmpcaisse.afficher_trier1());
      ui->prixtot->setModel(tmpcaisse.calcul_total());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                  QObject::tr("Produit modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_pb_rechercher_3_clicked()
{
    QString str=ui->lineEdit_rechercher->text();
    ui->tabrecherche_3->setModel(tmpcaisse.recherche(str));
}

void Login::on_pb_ajouter_6_clicked()
{
    int id_3 = ui->lineEdit_id_8->text().toInt();
    QString type_2= ui->lineEdit_type_3->text();
     int etat = ui->lineEdit_etat->text().toInt();
      QString materiels= ui->lineEdit_materiels->text();
  Rayon r(id_3,type_2,etat,materiels);
  bool test=r.ajouter_2();
  if(test)
{ui->tabrayon->setModel(tmprayon.afficher());
 ui->tabrayon_2->setModel(tmprayon.afficher_trier());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_supprimer_6_clicked()
{
    int id_3 = ui->lineEdit_id_9->text().toInt();
    bool test=tmprayon.supprimer_2(id_3);
    if(test)
    {ui->tabrayon->setModel(tmprayon.afficher());
     ui->tabrayon_2->setModel(tmprayon.afficher_trier());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Login::on_pb_modifier_5_clicked()
{
    int id_3 = ui->lineEdit_idmod_3->text().toInt();
    QString type_2=ui->lineEdit_typemod_3->text();
    int etat = ui->lineEdit_etatmod->text().toInt();
   QString materiels=ui->lineEdit_materielsmod->text();
   Rayon r(id_3,type_2,etat,materiels);
  bool test=r.modifier_2(id_3);
  if(test)
{ui->tabrayon->setModel(tmprayon.afficher());
 ui->tabrayon_2->setModel(tmprayon.afficher_trier());//refresh

QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                  QObject::tr("Produit modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pb_rechercher_4_clicked()
{
    QString str=ui->lineEdit_recherche->text();
    ui->tabrechercher->setModel(tmprayon.recherche_2(str));
}

void Login::on_pb_ajouter_2_clicked()
{
    int idcom = ui->lineEdit_idcom->text().toInt();
    int idfourn = ui->lineEdit_idfourn->text().toInt();
    QString catprod= ui->lineEdit_catprod->text();
  Commandes c(catprod,idfourn,idcom);
  bool test=c.ajouter();
  if(test)
{ui->tabcommandes->setModel(tmpcommandes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("Commande ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_supprimer_2_clicked()
{
    int idcom = ui->lineEdit_idcom_2->text().toInt();
    bool test=tmpcommandes.supprimer(idcom);
    if(test)
    {ui->tabcommandes->setModel(tmpcommandes.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Commande supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pb_modifier_clicked()
{
    int idcom = ui->lineEdit_idc->text().toInt();
    int idfourn= ui->lineEdit_idf->text().toInt();
    QString catprod= ui->lineEdit_c->text();
    Commandes f1(catprod,idfourn,idcom);
  bool test=f1.modifier(idcom);
  if(test)
{ui->tabcommandes->setModel(tmpcommandes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_rechercher_2_clicked()
{
    QString idcom=ui->lineEditrecherche_2->text();
    ui->tabrecherche_2->setModel(tmpcommandes.rechercher(idcom));
}

void Login::on_pb_ajouter_3_clicked()
{
    int idfourn = ui->lineEdit_idc_5->text().toInt();
    int numtel = ui->lineEdit_num_telfourn->text().toInt();
    QString nomfourn= ui->lineEdit_nomfourn->text();
    QString prenomfourn= ui->lineEdit_prenomfourn->text();
    QString catprod= ui->lineEdit_cat->text();
    four f1(numtel, idfourn,catprod,nomfourn,prenomfourn);
  bool test=f1.ajouter_3();
  if(test)
{ui->tabcommandes_3->setModel(tmpfour.afficher_2());
ui->tabcommandes_5->setModel(tmpfour.afficher_trier());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Fournisseur ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fourn"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_supprimer_3_clicked()
{
    int idcom = ui->lineEdit_idcom_6->text().toInt();
    bool test=tmpfour.supprimer_2(idcom);
    if(test)
    {ui->tabcommandes_3->setModel(tmpfour.afficher_2());
    ui->tabcommandes_5->setModel(tmpfour.afficher_trier());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_modifier_2_clicked()
{
    int idfourn = ui->lineEdit_idc_4->text().toInt();
    int numtel = ui->lineEdit_idf_6->text().toInt();
    QString nomfourn= ui->lineEdit_c_4->text();
    QString prenomfourn= ui->lineEdit_idf_7->text();
    QString catprod= ui->lineEdit_idf_8->text();
    four f1(idfourn,numtel,catprod,nomfourn,prenomfourn);
  bool test=f1.modifier_2(idfourn);
  if(test)
{ui->tabcommandes_3->setModel(tmpfour.afficher_2());
ui->tabcommandes_5->setModel(tmpfour.afficher_trier());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_rechercher_clicked()
{
    QString idfourn=ui->lineEditrecherche->text();
    ui->tabrecherche->setModel(tmpfour.rechercher(idfourn));
}




//asma


void Login::on_pb_ajouter_clicked()
    {
        int id = ui->lineEdit_id_4->text().toInt();
        QString nom= ui->lineEdit_nom_4->text();
        QString prenom= ui->lineEdit_prenom_4->text();
      Client e(id,nom,prenom);
      bool test=e.ajouter();
      if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

void Login::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_5->text().toInt();
bool test=tmpclient.supprimer(id);
if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_modifier_clicked()
{
  QString nom=ui->nom->text();
  QString prenom=ui->prenom->text();
   int id= ui->identifiant->text().toInt();

    bool test=tmpclient.modifier(id,nom,prenom);

    if(test)
    {
      ui->tabclient->setModel(tmpclient.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                    QObject::tr("Client modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


void Login::on_trier_clicked()
{
     ui->tabclient->setModel(tmpclient.trier());
}

void Login::on_rechercher_clicked()
{
    QString id=ui->idrech->text();
    ui->tablerech->setModel(tmpclient.recherche(id));
}

void Login::on_ajouter_2_clicked()
{
    {
        int id = ui->lineEdit_num_3->text().toInt();
       int point= ui->lineEdit_point->text().toInt();
        QString datee = ui->lineEdit_date_3->text();
      Carte c(point,id,datee);
      bool test=c.ajouter();
      if(test)
    {ui->tabcarte->setModel(tmpcarte.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un carte"),
                      QObject::tr("carte ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void Login::on_supprimer_5_clicked()
{
int id = ui->lineEdit_num_8->text().toInt();
bool test=tmpcarte.supprimer(id);
if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("carte supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Login::on_validerc_clicked()
    {
      int id=ui->numero_2->text().toInt();
      int point=ui->point_2->text().toInt();
       QString date= ui->date->text();

        bool test=tmpcarte.modifier(id,date,point);

        if(test)
        {
          ui->tabcarte->setModel(tmpcarte.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("modifier une carte"),
                        QObject::tr("Carte modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier une carte"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}
