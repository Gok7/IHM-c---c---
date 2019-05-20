/* 
 * File:   C_INFO.cpp
 * Author: flopyy
 * 
 * Created on 28 novembre 2013, 14:37
 */

#include "C_DATA.h"
#include "C_SECTION_CRITIQUE.h"
#define DEBUG
#ifdef DEBUG
#include <iostream>
using namespace std;
#endif
C_DATA::C_DATA() {
}

C_DATA::C_DATA(const C_DATA& orig) {
}

C_DATA::~C_DATA() {
}

void C_DATA::Ecrire(int &P_Valeur) {

    Verrou.P();
    Valeur = P_Valeur;
    cout << "C_DATA::Ecrire, Valeur = " << Valeur << endl;
    Verrou.V();
}

void C_DATA::Lire(int *P_Valeur) {

    Verrou.P();
    *P_Valeur = Valeur;
    Verrou.V();
}
//int C_DATA::Lire() {
//
//    Verrou.P();
//    int L_valeur=Valeur;
//    Verrou.V();
//    return L_valeur;
//}