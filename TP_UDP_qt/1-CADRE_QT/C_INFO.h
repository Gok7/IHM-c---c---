/* 
 * File:   C_INFO.h
 * Author: TL
 *
 * Created on 28 novembre 2013, 14:36
 */

#ifndef C_INFO_H
#define	C_INFO_H

#include "C_MUTEX.h"


class C_INFO {
public:
    C_INFO();
    int* Get_Position()
    {
        int* L_Info;
        Le_Verrou.P();
        L_Info=L_Position;
        Le_Verrou.V();
        return L_Info;
    }
    void Set_Position_valeur_1(int L_Info)
    {
        Le_Verrou.P();
        L_Position[0]=L_Info;
        Le_Verrou.V();
    }
    void Set_Position_valeur_2(int L_Info)
    {
        Le_Verrou.P();
        L_Position[1]=L_Info;
        Le_Verrou.V();
    }
private:
    int L_Position[2];
    C_MUTEX Le_Verrou;
};

#endif	/* C_INFO_H */

