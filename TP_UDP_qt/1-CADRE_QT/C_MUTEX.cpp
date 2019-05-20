/* 
 * File:   C_MUTEX.cpp
 * Author: Administrateur
 * 
 * Created on 14 novembre 2013, 15:14
 */
#include <windows.h>
#include "C_MUTEX.h"

C_MUTEX::C_MUTEX(bool P_Proprio) {
     H_Mutex=CreateMutex(NULL,P_Proprio,NULL);
     if(H_Mutex==NULL) throw("C_MUTEX : ERREUR CreateMutex");
}



C_MUTEX::~C_MUTEX() {
    if(H_Mutex) CloseHandle(H_Mutex);
}

