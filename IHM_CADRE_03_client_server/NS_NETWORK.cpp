
#include "NS_NETWORK.h"
#include <windows.h>
#include <winsock2.h>
namespace NETWORK {

    void Init_DLL_Socket() {
        WSADATA L_Info_DLL;
        WSAStartup(MAKEWORD(2, 0), &L_Info_DLL);
    }

    //---------------------------------------------------------

    void Fin_DLL_Socket() {
        WSACleanup();
    }
}
