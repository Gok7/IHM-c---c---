/* 
 * File:   C_THREAD.h
 * Author: mathieu
 *
 * Created on 14 novembre 2013, 10:34
 */

#ifndef C_THREAD_H
#define	C_THREAD_H
#include <windows.h>

class C_THREAD {
public:
    C_THREAD();
    static DWORD WINAPI Fonction_Thread(C_THREAD* P_Info);
    void Endors_Toi();
    void Reveille_Toi();
    void  Tue_Toi(DWORD P_Code=0);
    void Set_Priorite(DWORD P_Priorite);
    HANDLE Get_Handle();
    
    void Set_Affinite(DWORD P_Core);
    DWORD Synchronisation_Avec_Mort(DWORD P_Time_Out=INFINITE);
protected:
    virtual void Run()=0;    
    HANDLE H_Thread;
    DWORD TID;
};

#endif	/* C_THREAD_H */

