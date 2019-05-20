/* 
 * File:   C_SECTION_CRITIQUE.cpp
 * Author: Administrateur
 * 
 * Created on 14 novembre 2013, 14:44
 */

#include "C_SECTION_CRITIQUE.h"

C_SECTION_CRITIQUE::C_SECTION_CRITIQUE() {
    InitializeCriticalSection(&Section_Critique);
    
}

//------------------------------------------------------------------------------
C_SECTION_CRITIQUE::~C_SECTION_CRITIQUE() {
    DeleteCriticalSection(&Section_Critique);
}
//------------------------------------------------------------------------------
