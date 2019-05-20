/* 
 * File:   C_SERVEUR.cpp
 * Author: Flav
 * 
 * Created on 5 novembre 2013, 16:01
 */


#include <winsock.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "C_SERVEUR.h"



#define DEBUG_SOCKET
int Ok=0;

using namespace std;


C_SERVEUR::C_SERVEUR() {
   
    WSADATA L_Info_DLL;
    if (WSAStartup(MAKEWORD(2, 0), &L_Info_DLL) != 0) exit(0);
    
    
  H_Socket = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
    
    if (H_Socket == INVALID_SOCKET)
    {
        Affiche_Erreur();
    }
  
    Process_Locale.sin_family = AF_INET;
    Process_Locale.sin_port = htons(9999);
    Process_Locale.sin_addr.S_un.S_addr = INADDR_ANY;
    
     int L_OK = bind(H_Socket, (sockaddr*) &Process_Locale, sizeof(Process_Locale));
     
    
    if (L_OK == SOCKET_ERROR) {
        Affiche_Erreur();
    }
    
    Stockage_Info=nullptr;
    
    


#ifdef DEBUG_SOCKET 
    cout << L_Info_DLL.szDescription << endl;
#endif 
#ifdef DEBUG_SOCKET
    cout<<"Valeur du socket:   "<< H_Socket <<endl;
#endif
#ifdef DEBUG_SOCKET
    cout<<"Bind:    "<< L_OK <<endl;
#endif
    
}

//==============================================================================

C_SERVEUR::~C_SERVEUR() {
    
        int L_OK = WSACleanup();

#ifdef DEBUG_SOCKET
    if (L_OK == 0) cout << "WSACleanup   :  Ok" << endl;
    else cout << "WSACleanup :  ERREUR" << endl;
#endif
}

//==============================================================================

void C_SERVEUR::Affiche_Erreur()
{
    DWORD L_Code_Erreur = GetLastError();
    
    char L_Message[512];
    
    //FormatMessage ( FORMAT_MESSAGE_FROM_SYSTEM, NULL, L_Code_Erreur,0,L_Message,511,NULL);
    cerr << " -Erreur ["<<L_Code_Erreur<<"]   :  "<<L_Message<< endl;
    
}


//==============================================================================

void C_SERVEUR::Run()
{
    int L_Info[2];
    
    sockaddr_in L_Info_Distant;
while(1){
    cout<<"Reception !"<<endl;
    int L_Taille_Info = sizeof(L_Info_Distant);
    int L_Taille= recvfrom(H_Socket,(char*)&L_Info,sizeof(L_Info)-1,0,
          (sockaddr*)&L_Info_Distant, &L_Taille_Info); 
  
    #ifdef DEBUG_SOCKET
    cout<<"recvfrom - Taille:    "<< L_Taille <<endl;
    cout<<"Adresse client : "<<inet_ntoa(L_Info_Distant.sin_addr)<<endl;
    cout<<L_Info[0]<<" "<<L_Info[1]<<endl;
    #endif
    
    if (L_Taille == SOCKET_ERROR) Affiche_Erreur();
    if(L_Taille) {
        Stockage_Info->Set_Position_valeur_1(L_Info[0]);
        Stockage_Info->Set_Position_valeur_2(L_Info[1]);
    }
}
}
    
    

