/* 
 * File:   C_THREAD.h
 * Author: Administrateur
 *
 * Created on 14 novembre 2013, 10:42
 */

#include <windows.h>

#ifndef C_THREAD_H
#define	C_THREAD_H

class C_THREAD {
public:
      typedef enum{
        CORE_1=1,
        CORE_2=3,
        CORE_3=5,
        CORE_4=7
    }T_AFFINITE_CORE;
    
    typedef enum{
        BASSE=THREAD_PRIORITY_IDLE,
        INFERIEUR_NORMAL=THREAD_PRIORITY_BELOW_NORMAL,
        NORMAL=THREAD_PRIORITY_NORMAL,
        SUPERIEUR_NORMAL=THREAD_PRIORITY_ABOVE_NORMAL,
        HAUTE=THREAD_PRIORITY_HIGHEST,
        TEMPS_REEL=THREAD_PRIORITY_TIME_CRITICAL
    }T_PRIORITE_THREAD;
    
    C_THREAD();
    static DWORD WINAPI Fonction_Thread(C_THREAD*);
    virtual void Run()=0;
    void Set_Prorite(T_PRIORITE_THREAD);
    void Set_Affinite(DWORD P_Affinte);
    void Reveille_Toi();
    void Endors_Toi();
    void Tue_Toi();
    inline HANDLE Get_Handle();
    void Synchronsation_Avec_Mort();
    
protected:
    HANDLE H_Thread;
    DWORD TID;
};

HANDLE C_THREAD::Get_Handle()
{
    return H_Thread;
}

#endif	/* C_THREAD_H */

