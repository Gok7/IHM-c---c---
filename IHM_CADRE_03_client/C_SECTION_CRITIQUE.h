/* 
 * File:   C_SECTION_CRITIQUE.h
 * Author: Administrateur
 *
 * Created on 14 novembre 2013, 14:44
 */

#ifndef C_SECTION_CRITIQUE_H
#define	C_SECTION_CRITIQUE_H

#include <windows.h>

class C_SECTION_CRITIQUE {
public:
    C_SECTION_CRITIQUE();
    ~C_SECTION_CRITIQUE();
    inline void P();
    inline BOOL Tente_P(); 
    inline void V();
protected:
    CRITICAL_SECTION Section_Critique;    

};

//------------------------------------------------------------------------------
void C_SECTION_CRITIQUE::P()
{
    EnterCriticalSection(&Section_Critique);
}
//------------------------------------------------------------------------------
BOOL C_SECTION_CRITIQUE::Tente_P()
{
    return TryEnterCriticalSection(&Section_Critique);
}
//------------------------------------------------------------------------------
void C_SECTION_CRITIQUE::V()
{
    LeaveCriticalSection(&Section_Critique);
}
#endif	/* C_SECTION_CRITIQUE_H */

