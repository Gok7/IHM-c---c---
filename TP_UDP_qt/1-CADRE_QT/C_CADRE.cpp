/*
 * File:   C_CADRE.cpp
 * Author: TL
 *
 * Created on 4 décembre 2013, 15:35
 */

#include "C_CADRE.h" 


C_CADRE::C_CADRE() {
    widget.setupUi(this);
  
}

C_CADRE::~C_CADRE() {
}

//==============================================================================

void C_CADRE::Slot_Info()
{
    widget.Liste_Info->addItem(QString("Coucou"));
    widget.Liste_Info->scrollToBottom();
}

void C_CADRE::Slot_Info_1(int P_Valeur)
{
 widget.Liste_Info->addItem(QString("Slider_1 : "));
 widget.Liste_Info->addItem(QString::number(P_Valeur,10));
 widget.Liste_Info->scrollToBottom();
 
 Les_Infos->Set_Position_valeur_1(P_Valeur);
}

void C_CADRE::Slot_Info_2(int P_Valeur)
{
    widget.Liste_Info->addItem(QString("Slider_2 : "));
 widget.Liste_Info->addItem(QString::number(P_Valeur,10));
 widget.Liste_Info->scrollToBottom();
 
 Les_Infos->Set_Position_valeur_2(P_Valeur);
 
 
}