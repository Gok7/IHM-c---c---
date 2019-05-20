/*
 * File:   C_COURBE.cpp
 * Author: Nicolas
 *
 * Created on 5 décembre 2013, 14:04
 */
#include <math.h>
#include "C_COURBE.h"


C_COURBE::C_COURBE() {
    widget.setupUi(this);
    La_courbe = new QwtPlotCurve;
    La_courbe->attach(widget.Le_graphe);
    L_pas = 2*M_PI/(float)NB_POINTS;
    L_T =0.0;
    L_T2=0.0;
    L_coef_1 = widget.Le_Slider_1->value();
    L_coef_2 = widget.Le_Slider_1->value();

    for(int L_index=0;L_index<NB_POINTS;L_index++){
         
          L_X[L_index]=L_index;
          L_Y[L_index]=L_coef_1*sin(L_T)+L_coef_2*sin(2*L_T2);
          L_T+=L_pas;
    }

    La_courbe->setSamples(L_X,L_Y,NB_POINTS);
    widget.Le_graphe->replot();
}

C_COURBE::~C_COURBE() {
}


void C_COURBE::slot_coef(double P_coef)
{

    for(int L_index=0;L_index<NB_POINTS;L_index++){
         
          L_X[L_index]=L_index;
          L_Y[L_index]=P_coef*sin(L_T);
          L_T+=L_pas;
    }

    La_courbe->setSamples(L_X,L_Y,NB_POINTS);
    widget.Le_graphe->replot();
    
   
    for(int L_index=0;L_index<NB_POINTS;L_index++){
         
        L_coef_2=widget.Le_slider_2->value();
          L_X[L_index]=L_index;
          L_Y[L_index]=L_coef_2*sin(2*L_T2);
          L_T2+=L_pas;
    }

    La_courbe->setSamples(L_X,L_Y,NB_POINTS);
    widget.Le_graphe->replot(); 
}


