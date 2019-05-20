/* 
 * File:   C_THREAD.cpp
 * Author: mathieu
 * 
 * Created on 14 novembre 2013, 10:34
 */

#include "C_THREAD.h"
#include <windows.h>
#include <iostream>
using namespace std;

C_THREAD::C_THREAD() {
    H_Thread=CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Fonction_Thread, this, CREATE_SUSPENDED, &TID);
    if(H_Thread==NULL){
        throw("C_THREAD : Erreur CreateThread ");
    }
}

DWORD WINAPI C_THREAD::Fonction_Thread(C_THREAD* P_Objet){
    P_Objet->Run();
}

void C_THREAD::Endors_Toi(){
    cout<<"Je m'endors "<<endl;
    SuspendThread(H_Thread);
}

void C_THREAD::Reveille_Toi(){
    cout<<"Je me reveille "<<endl;
    ResumeThread(H_Thread);
}

void C_THREAD::Tue_Toi(DWORD P_Code){
    cout<<"Je meurs"<<endl;
    TerminateThread(H_Thread,P_Code);
}

void C_THREAD::Run(){
    
}

void C_THREAD::Set_Priorite(DWORD P_Priorite){
    SetThreadPriority(H_Thread,P_Priorite);
}
void C_THREAD::Set_Affinite(DWORD P_Core){
    SetThreadAffinityMask(H_Thread,P_Core);
}
HANDLE C_THREAD::Get_Handle(){
    return H_Thread;
}

DWORD C_THREAD::Synchronisation_Avec_Mort(DWORD P_Time_Out){
        return WaitForSingleObject(H_Thread, P_Time_Out);

}