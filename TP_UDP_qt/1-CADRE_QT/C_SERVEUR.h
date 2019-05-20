/* 
 * File:   C_SERVEUR.h
 * Author: Flav
 *
 * Created on 5 novembre 2013, 16:01
 */

#ifndef C_SERVEUR_H
#define	C_SERVEUR_H


#include "C_THREAD.h"
#include "C_INFO.h"



class C_SERVEUR : public C_THREAD 
{
public:
    virtual ~C_SERVEUR();
    C_SERVEUR();
    
    void Run();
    void Set_Info(C_INFO* L_Info)
    {
        Stockage_Info=L_Info;
    }    
protected:
    
    SOCKET H_Socket;
    sockaddr_in Process_Locale; 
    void Affiche_Erreur();
    C_INFO* Stockage_Info;

};

#endif	/* C_SERVEUR_H */

