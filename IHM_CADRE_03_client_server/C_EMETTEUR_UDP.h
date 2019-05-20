/* 
 * File:   C_EMETTEUR_UDP.h
 * Author: Administrateur
 *
 * Created on 20 novembre 2013, 16:22
 */

#ifndef C_EMETTEUR_UDP_H
#define	C_EMETTEUR_UDP_H

#include "C_THREAD.h"
#include "C_DATA.h"
#include <windows.h>


class C_EMETTEUR_UDP : protected C_THREAD {
public:

     void Stoppe_Toi();
     void Set_Data(C_DATA* P_Data);
     using   C_THREAD::Reveille_Toi;
     using   C_THREAD::Synchronisation_Avec_Mort;
     void Run();
protected:
    DWORD Execute();
    bool Fin_Thread=false;
    C_DATA* Data;
};

#endif	/* C_EMETTEUR_UDP_H */

