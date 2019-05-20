/* 
 * File:   C_EMETTEUR_UDP.cpp
 * Author: Administrateur
 * 
 * Created on 20 novembre 2013, 16:22
 */

#include "C_EMETTEUR_UDP.h"
#include "DEFINE.h"
#include <windows.h>
#define DEBUG
#ifdef DEBUG
#include <iostream>
using namespace std;
#define DBG(INFO) cerr<<INFO<<endl;
#else
#define DBG(INFO)
#endif

//------------------------------------------------------------------------------

DWORD C_EMETTEUR_UDP::Execute() {
    DBG("C_EMETTEUR_UDP::Execute() : debut");
    SOCKET L_Socket_Client;
    sockaddr_in L_Info_Process_Distant;

    L_Socket_Client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (L_Socket_Client == INVALID_SOCKET) throw ("C_EMETTEUR_UDP::Execute - socket");

    L_Info_Process_Distant.sin_family = AF_INET;
    L_Info_Process_Distant.sin_port = htons(PORT_COMMUNICATION_UDP);
    L_Info_Process_Distant.sin_addr.S_un.S_addr = inet_addr(ADRESSE_BROADCAST);

    bool L_Broadcast = true;
    int L_Resultat = setsockopt(L_Socket_Client, SOL_SOCKET, SO_BROADCAST,
            (char*) &L_Broadcast, sizeof (L_Broadcast));
    if (L_Resultat == SOCKET_ERROR) throw ("C_EMETTEUR_UDP::Execute - setsockopt SO_BROADCAST");

    int L_Valeur_UDP=0;
    int L_Taille=0;
    while (!Fin_Thread) {
         Data->Lire(&L_Valeur_UDP);
#ifdef DEBUG
        cout << "L_Valeur_UDP = " << L_Valeur_UDP << endl;
#endif
        L_Taille = sendto(L_Socket_Client, (char*) &L_Valeur_UDP, sizeof (L_Valeur_UDP),
                0, (sockaddr*) & L_Info_Process_Distant, sizeof (L_Info_Process_Distant));

        if (L_Taille == SOCKET_ERROR) Fin_Thread = true;
        Sleep(PERIODE_EMISSION_UDP);
    }
    closesocket(L_Socket_Client);
    DBG("C_EMETTEUR_UDP::Execute() : fin");

}
//------------------------------------------------------------------------------

void C_EMETTEUR_UDP::Stoppe_Toi() {
    DBG("C_EMETTEUR_UDP::Stoppe_Toi()");
    Fin_Thread = true;
}
//------------------------------------------------------------------------------

void C_EMETTEUR_UDP::Set_Data(C_DATA* P_Data) {
    DBG("C_EMETTEUR_UDP::Set_Data(C_DATA* P_Data)");
    Data = P_Data;
}

void C_EMETTEUR_UDP::Run() {
    DBG("C_EMETTEUR_UDP::Run()");
        Execute();
}

//doit être opérationnel pour la semaine prochaine