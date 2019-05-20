/* 
 * File:   C_CLIENT.h
 * Author: TL
 *
 * Created on 5 novembre 2013, 16:05
 */

#include <winsock.h>


#include "C_THREAD.h"
#include "C_INFO.h"



#ifndef C_CLIENT_H
#define	C_CLIENT_H

class C_CLIENT : public C_THREAD 
{   
public:
    C_CLIENT();
    ~C_CLIENT();
    void Run();
    void Set_Info(C_INFO* L_Info)
    {
        Stockage_Info=L_Info;
    }
        
protected:
    SOCKET H_Socket;
    sockaddr_in Process_Distant;
    void Affiche_Erreur();
    C_INFO* Stockage_Info;
    int Ancienne_Info[2]={};
    
    
};

#endif	/* C_CLIENT_H */

