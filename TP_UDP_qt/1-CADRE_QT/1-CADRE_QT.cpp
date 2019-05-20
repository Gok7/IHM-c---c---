/*
 * File:   1-CADRE_QT.cpp
 * Author: TL
 *
 * Created on 4 décembre 2013, 15:18
 */

#include <QApplication>

#include "C_CADRE.h"
#include "C_CLIENT.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    C_CADRE La_Fenetre;
    C_INFO Info_Client;
    La_Fenetre.Set_Info(&Info_Client);
    C_CLIENT Le_Client;
    Le_Client.Set_Info(&Info_Client);
    Le_Client.Reveille_Toi();
    
    La_Fenetre.show();

    // create and show your widgets here

   int L_Resultat = app.exec();
   Le_Client.Tue_Toi();
   return L_Resultat;
}
