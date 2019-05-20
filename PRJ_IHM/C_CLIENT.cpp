/* 
 * File:   C_CLIENT.cpp
 * Author: TL
 * 
 * Created on 5 novembre 2013, 16:05
 */

#include "C_CLIENT.h"
#include "C_INFO.h"
#include <winsock.h>
#include <cstdlib>
#include <iostream>


using namespace std;

#define DEBUG_SOCKET

C_CLIENT::C_CLIENT() {
    
    WSADATA L_Info_DLL;
    if (WSAStartup(MAKEWORD(2, 0), &L_Info_DLL) != 0) exit;
    
    Process_Distant.sin_family = AF_INET;
    Process_Distant.sin_port = htons(9999);
    Process_Distant.sin_addr.S_un.S_addr = INADDR_BROADCAST;
    
    bool Broadcast = true;
    
    H_Socket = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
   setsockopt(H_Socket, SOL_SOCKET, SO_BROADCAST, (char*)&Broadcast, sizeof(Broadcast));
    
    
    if (H_Socket == INVALID_SOCKET)
    {
        Affiche_Erreur();
    }
    
    Stockage_Info=nullptr;

#ifdef DEBUG_SOCKET 
    cout << L_Info_DLL.szDescription << endl;
#endif 
    
#ifdef DEBUG_SOCKET
    cout<<"Valeur du socket:   "<< H_Socket <<endl;
#endif   
    
}



C_CLIENT::~C_CLIENT() {
     int L_OK = WSACleanup();

#ifdef DEBUG_SOCKET
    if (L_OK == 0) cout << "WSACleanup   :  Ok" << endl;
    else cout << "WSACleanup :  ERREUR" << endl;
#endif
}


void C_CLIENT::Affiche_Erreur()
{
    DWORD L_Code_Erreur = GetLastError();
    
    char L_Message[512];
    
    FormatMessage ( FORMAT_MESSAGE_FROM_SYSTEM, NULL, L_Code_Erreur,
                    0,L_Message,511,NULL);
    cerr << " -Erreur ["<<L_Code_Erreur<<"]   :  "<<L_Message<<endl;
    
}

void C_CLIENT::Run()
{
   while(1){
       Sleep(100);
       cout<<"Envoie !"<<endl;
     
       int* L_Info;
       L_Info=Stockage_Info->Get_Position();
       if(L_Info[0] != Ancienne_Info[0] | L_Info[1] != Ancienne_Info[1] ){
       
        Ancienne_Info[0]=L_Info[0];
        Ancienne_Info[1]=L_Info[1];
        
    int L_Taille = sendto(H_Socket, (const char*)&Ancienne_Info, sizeof(Ancienne_Info),
            0, (sockaddr*) & Process_Distant,sizeof (Process_Distant));

    if (L_Taille == SOCKET_ERROR) {
        Affiche_Erreur();
    }
       
#ifdef DEBUG_SOCKET
    cout << "sendto - Taille  : " << L_Taille << endl;
    
    cout<<Ancienne_Info[0]<<"  "<<Ancienne_Info[1]<<endl;
#endif
   } }
}




//------------------------------------------------------------------------------



