/* 
 * File:   C_CADRE.h
 * Author: TL
 *
 * Created on 4 décembre 2013, 15:35
 */

#ifndef _C_CADRE_H
#define	_C_CADRE_H

#include "ui_C_CADRE.h"
#include "C_INFO.h"

class C_CADRE : public QMainWindow {
    Q_OBJECT
public:
    C_CADRE();
    virtual ~C_CADRE();
    void Set_Info(C_INFO* P_Info)
    {
        Les_Infos=P_Info;
    }
private:
    Ui::C_CADRE widget;
    C_INFO* Les_Infos;
    
    protected slots :
        void Slot_Info();
        void Slot_Info_1(int P_Valeur);
        void Slot_Info_2(int P_Valeur);
        
};

#endif	/* _C_CADRE_H */
