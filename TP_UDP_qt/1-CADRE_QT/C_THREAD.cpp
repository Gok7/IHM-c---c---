/* 
 * File:   C_THREAD.cpp
 * Author: Administrateur
 * 
 * Created on 14 novembre 2013, 10:42
 */
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

#include "C_THREAD.h"

C_THREAD::C_THREAD() 
{    
     H_Thread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Fonction_Thread,
                                                this,CREATE_SUSPENDED,&TID);  
     if(H_Thread==NULL) throw("C_THREAD : ERREUR CreateThread");
}

DWORD WINAPI C_THREAD::Fonction_Thread(C_THREAD* P_Objet)
{
    P_Objet->Run();
}

void C_THREAD::Set_Affinite(DWORD P_Affinte)
{
if(H_Thread) { 
    BOOL L_OK=SetThreadAffinityMask(H_Thread,P_Affinte);
     if(L_OK==0) throw("C_THREAD : ERREUR SetThreadAffinityMask");
}
}

void C_THREAD::Set_Prorite(T_PRIORITE_THREAD P_Priorite)
{
    if(H_Thread) {
BOOL L_OK=SetThreadPriority(H_Thread,P_Priorite);
if(L_OK==0) throw("C_THREAD : ERREUR SetThreadPriority");
}
}

void C_THREAD::Endors_Toi()
{
    if(H_Thread) SuspendThread(H_Thread);
}

void C_THREAD::Reveille_Toi()
{
    if(H_Thread) ResumeThread(H_Thread);
}

void C_THREAD::Tue_Toi()
{
    if(H_Thread) TerminateThread(H_Thread,0);
}

void C_THREAD::Synchronsation_Avec_Mort()
{
    if(H_Thread) WaitForSingleObject(H_Thread,INFINITE);
}
