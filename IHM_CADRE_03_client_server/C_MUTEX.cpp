/* 
 * File:   C_MUTEX.cpp
 * Author: mathieu
 * 
 * Created on 14 novembre 2013, 15:13
 */

#include "C_MUTEX.h"

C_MUTEX::C_MUTEX(bool P_Proprietaire) {
    H_Mutex=CreateMutex(NULL,P_Proprietaire,NULL);
    
    if(H_Mutex==NULL) throw("C_MUTEX : erreur createMutex ");
}


C_MUTEX::~C_MUTEX() {
    if(H_Mutex) CloseHandle(H_Mutex);
}
