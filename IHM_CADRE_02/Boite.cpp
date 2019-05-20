#include <cstdlib>
#include <windef.h>
#include <windows.h>
#include <iostream>
#include "resource.h"
#include "Boite.h"
#include <winuser.h>
using namespace std;

LRESULT CALLBACK Gestion_Message_Boite(HWND P_Handle,
        UINT P_Message, WPARAM P_Info_16, LPARAM P_Info_32) {

    LRESULT L_Resultat = FALSE;


    switch (P_Message) {
        case WM_DESTROY: cerr << "WM_DESTROY" << endl;
            break;
        case WM_COMMAND: cerr << "WM_COMMAND" << endl;
            switch (P_Info_16) {
                case ID_ITEM_COUCOU: EndDialog(P_Handle, 0);
                    L_Resultat = true;
                    break;
                default : cerr<<P_Info_16<<P_Info_32<<endl;
            }
            break;
    }

    //return DefWindowProc(P_Fenetre, P_Message, P_Info_16, P_Info_32);
    //compartement par défaut d'une fenêtre windows

    return L_Resultat;
}

void Afficher_Boite(HWND P_Fenetre_Mere, HINSTANCE P_Instance) {

    MessageBox(P_Instance,MAKEINTRESOURCE(ID_BOITE_INFO),P_Fenetre_Mere,
            (DLGPROC)Gestion_Message_Boite());
}


//a faire : progressbar controlé par un slider
//communication slider / processbar
//obtenir les handles pour communiquer
//GetDlgItem 
//sendMessage vers l'handle