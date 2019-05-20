//commande fichier .rc : WINDRES -i boite.rc -o boite.res -O coff
//propriété->linker->libraries->add file-> boite.res

#include <cstdlib>
#include <windef.h>
#include <windows.h>
#include <iostream>
#include "resource.h"
#include <winuser.h>
using namespace std;

#define NOM_MODELE_FENETRE "Modele_de_fenetre_exemple_unique98648"
#define TITRE_FENETRE "Terminator_application"
#define RESOLUTION_LARGEUR 400
#define RESOLUTION_HAUTEUR 300
HWND Fenetre_Principale;
HINSTANCE Instance_Application;

//------------------------------------------------------------------------------
//
//void Gestion_Items_Menu(UINT P_Info) {
//
//    int msgboxID;
//
//    switch (P_Info) {
//
//        case ID_ITEM_COUCOU: cerr << "ID_ITEM_COUCOU" << endl;
//            MessageBox(Fenetre_Principale, "coucou", "WARNING",
//                    MB_ICONWARNING | MB_RETRYCANCEL | MB_DEFBUTTON2);
//            break;
//        case ID_ITEM_QUITTER: cerr << "ID_ITEM_QUITTER" << endl;
//            msgboxID = MessageBox(Fenetre_Principale, "Quitter : t'es sur ? ", "WARNING",
//                    MB_YESNO);
//            
//            Afficher_Boite(Fenetre_Principale,Instance_Application);
//            switch (msgboxID) {
//                case IDYES:
//                    PostQuitMessage(WM_QUIT);
//                    break;
//                case IDNO:
//                    MessageBox(Fenetre_Principale,
//                            "Vous avez gagner une twingo sur www.twingogratos.com \n reference : 47474fz641",
//                            "Felicitation", 0);
//            }
//            break;
//    }
//}
//
////------------------------------------------------------------------------------
//
//LRESULT CALLBACK Gestion_Event_Fenetre_Principale(HWND P_Fenetre,
//        UINT P_Message, WPARAM P_Info_16, LPARAM P_Info_32) {
//
//    switch (P_Message) {
//        case WM_DESTROY: cerr << "WM_DESTROY" << endl;           
//        break;
//        case WM_COMMAND: cerr << "WM_COMMAND" << endl;
//            Gestion_Items_Menu(P_Info_16);
//            break;
//        default:cerr << "Message : " << P_Message << "," << P_Info_16 << "," <<
//                    P_Info_32 << endl;
//    }
//
//    return DefWindowProc(P_Fenetre, P_Message, P_Info_16, P_Info_32);
//    //compartement par défaut d'une fenêtre windows
//}

//------------------------------------------------------------------------------

void Creation_Fenetre(HINSTANCE P_Instance) {

    WNDCLASSEX L_Modele_Fenetre;

    ZeroMemory(&L_Modele_Fenetre, sizeof (WNDCLASSEX));

    L_Modele_Fenetre.cbSize = sizeof (WNDCLASSEX);
    L_Modele_Fenetre.style = CS_HREDRAW | CS_VREDRAW;
    // changer le style de la fenetre si redimensionnement vertical ou horizontal
    L_Modele_Fenetre.lpfnWndProc = Gestion_Event_Fenetre_Principale;
    L_Modele_Fenetre.hInstance = P_Instance;
    L_Modele_Fenetre.hCursor = LoadCursor(NULL, IDC_ARROW); //curseur par defaut
    L_Modele_Fenetre.hbrBackground = (HBRUSH) COLOR_WINDOW;
    L_Modele_Fenetre.lpszClassName = NOM_MODELE_FENETRE;
    L_Modele_Fenetre.hIcon = LoadIcon(NULL, IDI_WARNING);

    L_Modele_Fenetre.lpszMenuName=MAKEINTRESOURCE(MON_MENU);
    
    RegisterClassEx(&L_Modele_Fenetre);

}
//------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE P_Instance, HINSTANCE,
        LPSTR P_Ligne_Commande, int P_Mode_Affichage) {

    Instance_Application=P_Instance;
    MSG L_Message;
    long long L_compteur=0;
    Creation_Fenetre(P_Instance);
    Fenetre_Principale = CreateWindowEx(0,
            NOM_MODELE_FENETRE,
            TITRE_FENETRE,
            WS_OVERLAPPEDWINDOW, //indique si on accepte le surchargement graphique
            0, //X
            0, //Y
            RESOLUTION_LARGEUR,
            RESOLUTION_HAUTEUR,
            (HWND) NULL, //pas de parent
            NULL, //pas de menu
            P_Instance,
            NULL);

    ShowWindow(Fenetre_Principale, P_Mode_Affichage);

    while (GetMessage(&L_Message, NULL, 0, 0)) {
        TranslateMessage(&L_Message);
        DispatchMessage(&L_Message);
        
    }
    
    UnregisterClass(NOM_MODELE_FENETRE,P_Instance);
    return 0;
}
//------------------------------------------------------------------------------