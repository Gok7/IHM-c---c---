/********************************************************************************
** Form generated from reading UI file 'C_COURBE.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURBE_H
#define UI_C_COURBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"
#include "qwt_slider.h"

QT_BEGIN_NAMESPACE

class Ui_C_COURBE
{
public:
    QAction *action_Quitter;
    QWidget *centralwidget;
    QwtPlot *Le_graphe;
    QwtSlider *Le_Slider_1;
    QwtSlider *Le_slider_2;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *C_COURBE)
    {
        if (C_COURBE->objectName().isEmpty())
            C_COURBE->setObjectName(QStringLiteral("C_COURBE"));
        C_COURBE->resize(752, 390);
        action_Quitter = new QAction(C_COURBE);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralwidget = new QWidget(C_COURBE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Le_graphe = new QwtPlot(centralwidget);
        Le_graphe->setObjectName(QStringLiteral("Le_graphe"));
        Le_graphe->setGeometry(QRect(40, 70, 400, 200));
        Le_Slider_1 = new QwtSlider(centralwidget);
        Le_Slider_1->setObjectName(QStringLiteral("Le_Slider_1"));
        Le_Slider_1->setGeometry(QRect(510, 50, 60, 250));
        Le_Slider_1->setUpperBound(1);
        Le_Slider_1->setTotalSteps(10u);
        Le_Slider_1->setSingleSteps(1u);
        Le_slider_2 = new QwtSlider(centralwidget);
        Le_slider_2->setObjectName(QStringLiteral("Le_slider_2"));
        Le_slider_2->setGeometry(QRect(630, 60, 60, 250));
        Le_slider_2->setUpperBound(1);
        C_COURBE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(C_COURBE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 752, 21));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        C_COURBE->setMenuBar(menubar);
        statusbar = new QStatusBar(C_COURBE);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        C_COURBE->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(action_Quitter);

        retranslateUi(C_COURBE);
        QObject::connect(action_Quitter, SIGNAL(triggered()), C_COURBE, SLOT(close()));
        QObject::connect(Le_Slider_1, SIGNAL(valueChanged(double)), C_COURBE, SLOT(slot_coef(double)));
        QObject::connect(Le_slider_2, SIGNAL(valueChanged(double)), C_COURBE, SLOT(slot_coef(double)));

        QMetaObject::connectSlotsByName(C_COURBE);
    } // setupUi

    void retranslateUi(QMainWindow *C_COURBE)
    {
        C_COURBE->setWindowTitle(QApplication::translate("C_COURBE", "Courbe", 0));
        action_Quitter->setText(QApplication::translate("C_COURBE", "&Quitter", 0));
        menu_Fichier->setTitle(QApplication::translate("C_COURBE", "&Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class C_COURBE: public Ui_C_COURBE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURBE_H
