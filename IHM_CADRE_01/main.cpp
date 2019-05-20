/* 
 * File:   main.cpp
 * Author: flopyy
 *
 * Created on 27 novembre 2013, 14:27
 */

#include <cstdlib>
#include <windef.h>
#include <windows.h>
#include <iostream>

using namespace std;

#define NOM_MODELE_FENETRE "Modele_de_fenetre_exemple_unique98648"
#define TITRE_FENETRE "Terminator_application"
#define RESOLUTION_LARGEUR 800
#define RESOLUTION_HAUTEUR 600
HWND Fenetre_Principale;

//------------------------------------------------------------------------------

LRESULT CALLBACK Gestion_Event_Fenetre_Principale(HWND P_Fenetre,
        UINT P_Message, WPARAM P_Info_16, LPARAM P_Info_32) {

    switch(P_Message){
        case WM_DESTROY : cerr<<"WM_DESTROY"<<endl;
        PostQuitMessage(WM_QUIT);
        break;
        default:cerr<<"Message : "<<P_Message<<","<<P_Info_16<<","<<
                P_Info_32<<endl;
        
    }
    
    
    return DefWindowProc(P_Fenetre, P_Message, P_Info_16, P_Info_32);
    //compartement par défaut d'une fenêtre windows
}

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

    RegisterClassEx(&L_Modele_Fenetre);

}
//------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE P_Instance, HINSTANCE,
        LPSTR P_Ligne_Commande, int P_Mode_Affichage) {

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