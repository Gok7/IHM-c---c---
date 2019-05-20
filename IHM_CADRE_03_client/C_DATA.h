/* 
 * File:   C_DATA.h
 * Author: flopyy
 *
 * Created on 28 novembre 2013, 14:37
 */

#ifndef C_DATA_H
#define	C_DATA_H

#include "C_SECTION_CRITIQUE.h"


class C_DATA {
public:
    C_DATA();
    C_DATA(const C_DATA& orig);
    virtual ~C_DATA();
    void Ecrire(int &P_Valeur);
    void Lire(int *P_Valeur);
//    int Lire();

protected:
    int Valeur=0;
    C_SECTION_CRITIQUE Verrou;
    
};

#endif	/* C_DATA_H */

