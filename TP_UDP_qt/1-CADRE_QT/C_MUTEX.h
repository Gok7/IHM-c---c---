/* 
 * File:   C_MUTEX.h
 * Author: Administrateur
 *
 * Created on 14 novembre 2013, 15:14
 */

#ifndef C_MUTEX_H
#define	C_MUTEX_H
#include <windows.h>

class C_MUTEX {
public:
    C_MUTEX(bool P_Proprio=false);
   
    ~C_MUTEX();
    inline DWORD P(DWORD P_Time_Out=INFINITE);
    inline BOOL V();
    inline HANDLE Get_Handle();
private:
    HANDLE H_Mutex;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD C_MUTEX::P(DWORD P_Time_Out)
{
    return WaitForSingleObject(H_Mutex,P_Time_Out);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

BOOL C_MUTEX::V()
{
    return ReleaseMutex(H_Mutex);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
HANDLE C_MUTEX::Get_Handle()
{
    return H_Mutex;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif	/* C_MUTEX_H */

