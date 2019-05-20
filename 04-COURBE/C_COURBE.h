/* 
 * File:   C_COURBE.h
 * Author: Nicolas
 *
 * Created on 5 décembre 2013, 14:04
 */

#ifndef _C_COURBE_H
#define	_C_COURBE_H

#define NB_POINTS 100
#include "ui_C_COURBE.h"
#include "qwt_plot_curve.h"


class C_COURBE : public QMainWindow {
    Q_OBJECT
public:
    C_COURBE();
    virtual ~C_COURBE();
private:
    Ui::C_COURBE widget;
    QwtPlotCurve* La_courbe;
    double L_X[NB_POINTS];
    double L_Y[NB_POINTS];
    double L_pas;
    double L_T;
    double L_coef_1;
    double L_T2;
    double L_X2[NB_POINTS];
    double L_Y2[NB_POINTS];
    double L_coef_2;
    
   
    
    protected slots:
        
    void slot_coef(double P_coef);
    
};

#endif	/* _C_COURBE_H */
