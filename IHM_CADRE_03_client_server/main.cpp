//commande fichier .rc :
/*
cd C:\Users\flopyy\Documents\NetBeansProjects\IHM\IHM_CADRE_03_client_server
WINDRES -i boite.rc -o boite.res -O coff
  */
//propriété->linker->libraries->add file-> boite.res

#include <cstdlib>
#include <windef.h>
#include <windows.h> 
#include <iostream>
#include "resource.h"
#include <commctrl.h>
#include "C_DATA.h"
#include "C_EMETTEUR_UDP.h"
#include <winsock2.h>
#include "NS_NETWORK.h"
using namespace std;

//------------------------------------------------------------------------------
#define DEBUG
#ifdef DEBUG
#define DBG(INFO) cerr<<INFO<<endl;
#else
#define DBG(INFO)
#endif

HINSTANCE Instance_Application;
C_DATA* Data;
C_EMETTEUR_UDP* Emetteur_UDP;
//------------------------------------------------------------------------------

void On_Scrool(HWND P_Handle, WPARAM P_Info_16, LPARAM P_Info32) {
    //DBG(P_Info32);

    HWND L_Slider_1 = GetDlgItem(P_Handle, IDC_SLIDER1);
    HWND L_Barre_Progression_1 = GetDlgItem(P_Handle, IDC_PROGRESS1);
    int L_Position_Curseur_1 = SendMessage(L_Slider_1, TBM_GETPOS, 0, 0);
    SendMessage(L_Barre_Progression_1, PBM_SETPOS, L_Position_Curseur_1, 0);
    Data->Ecrire(L_Position_Curseur_1);
    
    HWND L_Slider_2 = GetDlgItem(P_Handle, IDC_SLIDER2);
    HWND L_Barre_Progression_2 = GetDlgItem(P_Handle, IDC_PROGRESS2);
    int L_Position_Curseur_2 = SendMessage(L_Slider_2, TBM_GETPOS, 0, 0);
    SendMessage(L_Barre_Progression_2, PBM_SETPOS, 100 - L_Position_Curseur_2, 0);

}
//------------------------------------------------------------------------------

void On_Close() {

    DBG("WM_CLOSE");
    Emetteur_UDP->Stoppe_Toi();
    Emetteur_UDP->Synchronisation_Avec_Mort();
    if (Emetteur_UDP) delete Emetteur_UDP;
    if (Data) delete Data;
    NETWORK::Fin_DLL_Socket();
    PostQuitMessage(WM_QUIT);
}
//------------------------------------------------------------------------------

void On_Command(HWND P_Handle, WPARAM P_Info_16, LPARAM P_Info_32) {

    switch (P_Info_16) {
        case WM_COMMAND: DBG("WM_COMMAND");
            break;
        case IDM__QUITTER1:On_Close();
            break;
        //case : IDM
    }
}
//------------------------------------------------------------------------------

void On_InitDialog(HWND P_Handle) {

    DBG("On_InitDialog");
    HWND L_Barre_Progression_1 = GetDlgItem(P_Handle, IDC_PROGRESS1);
    SendMessage(L_Barre_Progression_1, PBM_SETPOS, 0, 0);
    SendMessage(L_Barre_Progression_1, PBM_SETRANGE, 0, MAKELONG(0, 100));

    HWND L_Barre_Progression_2 = GetDlgItem(P_Handle, IDC_PROGRESS2);
    SendMessage(L_Barre_Progression_2, PBM_SETPOS, 0, 0);
    SendMessage(L_Barre_Progression_2, PBM_SETRANGE, 0, MAKELONG(0, 100));
}
//-----------------------------------------------------------------------------

BOOL CALLBACK Gestion_Message_Boite(HWND P_Handle,
        UINT P_Message, WPARAM P_Info_16, LPARAM P_Info_32) {

    BOOL L_Resultat = FALSE;

    switch (P_Message) {
        case WM_INITDIALOG: On_InitDialog(P_Handle);
            L_Resultat = true;
            break;
        case WM_COMMAND: On_Command(P_Handle, P_Info_16, P_Info_32);
            L_Resultat = true;
            break;
        case WM_HSCROLL: On_Scrool(P_Handle, P_Info_16, P_Info_32);
            L_Resultat = true;
            break;
        case WM_VSCROLL: On_Scrool(P_Handle, P_Info_16, P_Info_32);
            L_Resultat = true;
            break;
        case WM_CLOSE: On_Close();
            L_Resultat = true;
            break;
    }

    return L_Resultat;
}

//------------------------------------------------------------------------------
//void Afficher_Boite(HWND P_Instance, HINSTANCE P_HInstance) {
//
//    MessageBox(NULL, (LPCSTR),(LPCSTR) NULL,MB_OKCANCEL);
//}

//------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE P_Instance, HINSTANCE hPrevInstance,
        LPSTR P_Ligne_Commande, int P_Mode_Affichage) {
    MSG L_Message;

    Instance_Application = P_Instance;
    NETWORK::Init_DLL_Socket();
    Data = new C_DATA;
    Emetteur_UDP = new C_EMETTEUR_UDP;
    Emetteur_UDP->Set_Data(Data);
    Emetteur_UDP->Reveille_Toi();

    DialogBoxParam(P_Instance, (LPCTSTR) MA_BOITE, 0, Gestion_Message_Boite, 0);

    while (GetMessage(&L_Message, NULL, 0, 0)) {
        TranslateMessage(&L_Message);
        DispatchMessage(&L_Message);
    }
    return 0;
}
//------------------------------------------------------------------------------


//a faire  : chaque mouvement de slider on envoi les données dans une structure.
//thread reseau pour envoyer toute les 100 ms la struct.
//thread avec protection mutex
//choix entre console et UI.
//voir WM_TIMER
//
//DWORD lpIPAddress;
//
//LRESULT SM = SendMessage(hWndIPAddress, IPM_GETADDRESS, 0, (LPARAM)(LPDWORD)&lpIPAddress);
//
//BYTE IPPart1 = FIRST_IPADDRESS((LPARAM)lpIPAddress);
//BYTE IPPart2 = SECOND_IPADDRESS((LPARAM)lpIPAddress);
//BYTE IPPart3 = THIRD_IPADDRESS((LPARAM)lpIPAddress);
//BYTE IPPart4 = FOURTH_IPADDRESS((LPARAM)lpIPAddress);
//
//
//AnsiString ip = AnsiString(IPPart1) + AnsiString(".") +
//                AnsiString(IPPart2) + AnsiString(".") +
//                AnsiString(IPPart3) + AnsiString(".") +
//                AnsiString(IPPart4);
//
//ShowMessage("IP Address " + ip);