/* 
 * File:   3-BOITE.cpp
 * Author: TL
 *
 * Created on 28 novembre 2013, 09:39
 */

#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <commctrl.h>
#include "resource.h"
#include "C_INFO.h"
#include "C_CLIENT.h"
#include "C_SERVEUR.h"

using namespace std;

/*
 * 
 */

#define DEBUG 1

#ifdef DEBUG
#define DBG(INFO) cerr<<INFO<<endl;
#else
#define DBG(INFO)
#endif

HINSTANCE Instance;
HWND Le_Slider_Client_1;
HWND La_Barre_Progression_1;
HWND Le_Slider_Client_2;
HWND La_Barre_Progression_2;

C_INFO Information_Client;
C_INFO Information_Serveur;

C_CLIENT Le_Client;
C_SERVEUR Le_Serveur;


void On_Close();



void Gestion_Barre(LPARAM P_Info_32)
{
    DBG("WM_TIMER");

        int* L_Position=Information_Serveur.Get_Position();
        SendMessage(La_Barre_Progression_1,PBM_SETPOS,L_Position[0],0);
        SendMessage(La_Barre_Progression_2,PBM_SETPOS,L_Position[1],0);
}



//=======================================================================================

void On_HScroll(LPARAM P_Info_32)
{
    DBG("WM_HSCROLL");
    
    if((HWND)P_Info_32==Le_Slider_Client_1)
    {
        int L_Position=SendMessage(Le_Slider_Client_1,TBM_GETPOS,0,0);
        Information_Client.Set_Position_valeur_1(L_Position);
    }
    if((HWND)P_Info_32==Le_Slider_Client_2)
    {
        int L_Position=SendMessage(Le_Slider_Client_2,TBM_GETPOS,0,0);
        Information_Client.Set_Position_valeur_2(L_Position);
    }
    
}



//=======================================================================================


void On_Init_Dialogue(HWND P_Handle)
{

 
    
    HWND L_Barre_Progression=GetDlgItem(P_Handle,ID_BARRE_PROGRESSION_1);
    SendMessage(L_Barre_Progression,PBM_SETBARCOLOR,0,RGB(0,255,0));
    SendMessage(L_Barre_Progression,PBM_SETRANGE,FALSE,MAKELONG(0,100));
    
    HWND L_Slider=GetDlgItem(P_Handle,IDC_SLIDER1);
    SendMessage(L_Slider,TBM_SETRANGE,FALSE,MAKELONG(0,100));
    SendMessage(L_Slider,TBM_SETPOS,TRUE,50);
    Le_Slider_Client_1=L_Slider;
    La_Barre_Progression_1=L_Barre_Progression;
    
    L_Barre_Progression=GetDlgItem(P_Handle,ID_BARRE_PROGRESSION_2);
    SendMessage(L_Barre_Progression,PBM_SETBARCOLOR,0,RGB(0,255,0));
    SendMessage(L_Barre_Progression,PBM_SETRANGE,FALSE,MAKELONG(0,100));
    
    L_Slider=GetDlgItem(P_Handle,IDC_SLIDER2);
    SendMessage(L_Slider,TBM_SETRANGE,FALSE,MAKELONG(0,100));
    SendMessage(L_Slider,TBM_SETPOS,TRUE,50);
    Le_Slider_Client_2=L_Slider;
    La_Barre_Progression_2=L_Barre_Progression;
    
    Le_Client.Set_Info(&Information_Client);
    Le_Client.Reveille_Toi();
    
    Le_Serveur.Set_Info(&Information_Serveur);
    Le_Serveur.Reveille_Toi();
    
     SetTimer(P_Handle,10,100,NULL);
    
    
}

//=======================================================================================

void On_Close()
{
    DBG("WM_CLOSE");
    Le_Client.Tue_Toi();
    Le_Serveur.Tue_Toi();
    PostQuitMessage(WM_QUIT);
}

//=======================================================================================

LRESULT CALLBACK Gestion_Messages_Boite(HWND P_Handle,UINT P_Message, WPARAM P_Info_16, LPARAM P_Info_32)
{
   LRESULT L_Resultat=FALSE; 
   
    switch(P_Message)
    {
        case WM_INITDIALOG : On_Init_Dialogue(P_Handle); break;
        case WM_CLOSE : On_Close();
                        L_Resultat=TRUE;
                        break;
        case WM_HSCROLL : On_HScroll(P_Info_32);
                         L_Resultat=TRUE;
                        break;
        case WM_TIMER : Gestion_Barre(P_Info_32);
                        L_Resultat=TRUE;
                        break;
    }
    
    return L_Resultat;
}


//=======================================================================================

int WINAPI WinMain(HINSTANCE P_Instance, HINSTANCE, LPSTR P_Ligne_Commande, int P_Mode_Affichage)
{
    
     MSG L_Message;
     Instance = P_Instance;
             
    DialogBox(P_Instance,MAKEINTRESOURCE(ID_BOITE_DIALOGUE),NULL,(DLGPROC)Gestion_Messages_Boite);
   
    
    
    
    while(GetMessage(&L_Message,NULL,0,0))
    {
        TranslateMessage(&L_Message);
        DispatchMessage(&L_Message);
    }
}


//=======================================================================================

