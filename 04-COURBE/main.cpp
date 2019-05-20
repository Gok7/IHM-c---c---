/*
 * File:   main.cpp
 * Author: Nicolas
 *
 * Created on 5 décembre 2013, 14:02
 */

#include <QApplication>
#include "C_COURBE.h"

int main(int argc, char *argv[]) {


    QApplication app(argc, argv);
    C_COURBE fenetre;
     fenetre.show();
     
    int L_resultat= app.exec();
    
    return L_resultat;
}
