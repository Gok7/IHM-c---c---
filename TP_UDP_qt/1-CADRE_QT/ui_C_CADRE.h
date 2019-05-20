/********************************************************************************
** Form generated from reading UI file 'C_CADRE.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_CADRE_H
#define UI_C_CADRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_C_CADRE
{
public:
    QAction *action_Quitter;
    QAction *action_Test;
    QAction *action_Binaire;
    QAction *action_Hexa;
    QAction *action_Oct;
    QAction *action_Decimal;
    QWidget *centralwidget;
    QSlider *Le_Slider;
    QProgressBar *La_Barre_Progression;
    QPushButton *pushButton;
    QListWidget *Liste_Info;
    QProgressBar *La_Barre_Progression_2;
    QSlider *Le_Slider_2;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *C_CADRE)
    {
        if (C_CADRE->objectName().isEmpty())
            C_CADRE->setObjectName(QStringLiteral("C_CADRE"));
        C_CADRE->resize(576, 609);
        C_CADRE->setCursor(QCursor(Qt::CrossCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Counter-Strike Source-vrai/game.ico"), QSize(), QIcon::Normal, QIcon::Off);
        C_CADRE->setWindowIcon(icon);
        C_CADRE->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        action_Quitter = new QAction(C_CADRE);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        action_Test = new QAction(C_CADRE);
        action_Test->setObjectName(QStringLiteral("action_Test"));
        action_Binaire = new QAction(C_CADRE);
        action_Binaire->setObjectName(QStringLiteral("action_Binaire"));
        action_Hexa = new QAction(C_CADRE);
        action_Hexa->setObjectName(QStringLiteral("action_Hexa"));
        action_Oct = new QAction(C_CADRE);
        action_Oct->setObjectName(QStringLiteral("action_Oct"));
        action_Decimal = new QAction(C_CADRE);
        action_Decimal->setObjectName(QStringLiteral("action_Decimal"));
        centralwidget = new QWidget(C_CADRE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Le_Slider = new QSlider(centralwidget);
        Le_Slider->setObjectName(QStringLiteral("Le_Slider"));
        Le_Slider->setGeometry(QRect(80, 30, 361, 16));
        Le_Slider->setMaximum(100);
        Le_Slider->setOrientation(Qt::Horizontal);
        La_Barre_Progression = new QProgressBar(centralwidget);
        La_Barre_Progression->setObjectName(QStringLiteral("La_Barre_Progression"));
        La_Barre_Progression->setGeometry(QRect(40, 190, 91, 371));
        La_Barre_Progression->setValue(0);
        La_Barre_Progression->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 90, 181, 131));
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../Downloads/star-wars-pulp-fiction-boba-fett-darth-vader-pulp-fiction-shadow-art-star-wars-starwars.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(112, 72));
        Liste_Info = new QListWidget(centralwidget);
        Liste_Info->setObjectName(QStringLiteral("Liste_Info"));
        Liste_Info->setGeometry(QRect(310, 250, 251, 321));
        La_Barre_Progression_2 = new QProgressBar(centralwidget);
        La_Barre_Progression_2->setObjectName(QStringLiteral("La_Barre_Progression_2"));
        La_Barre_Progression_2->setGeometry(QRect(160, 190, 91, 371));
        La_Barre_Progression_2->setValue(0);
        La_Barre_Progression_2->setOrientation(Qt::Vertical);
        Le_Slider_2 = new QSlider(centralwidget);
        Le_Slider_2->setObjectName(QStringLiteral("Le_Slider_2"));
        Le_Slider_2->setGeometry(QRect(80, 70, 361, 16));
        Le_Slider_2->setMaximum(100);
        Le_Slider_2->setOrientation(Qt::Horizontal);
        C_CADRE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(C_CADRE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 576, 21));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        C_CADRE->setMenuBar(menubar);
        statusbar = new QStatusBar(C_CADRE);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        C_CADRE->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(action_Test);
        menu_Fichier->addSeparator();
        menu_Fichier->addAction(action_Decimal);
        menu_Fichier->addAction(action_Oct);
        menu_Fichier->addAction(action_Hexa);
        menu_Fichier->addAction(action_Binaire);
        menu_Fichier->addSeparator();
        menu_Fichier->addAction(action_Quitter);

        retranslateUi(C_CADRE);
        QObject::connect(action_Quitter, SIGNAL(triggered()), C_CADRE, SLOT(close()));
        QObject::connect(Le_Slider, SIGNAL(sliderMoved(int)), La_Barre_Progression, SLOT(setValue(int)));
        QObject::connect(Le_Slider, SIGNAL(valueChanged(int)), La_Barre_Progression, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), C_CADRE, SLOT(Slot_Info()));
        QObject::connect(Le_Slider, SIGNAL(sliderMoved(int)), C_CADRE, SLOT(Slot_Info_1(int)));
        QObject::connect(Le_Slider_2, SIGNAL(sliderMoved(int)), La_Barre_Progression_2, SLOT(setValue(int)));
        QObject::connect(Le_Slider_2, SIGNAL(sliderMoved(int)), C_CADRE, SLOT(Slot_Info_2(int)));

        QMetaObject::connectSlotsByName(C_CADRE);
    } // setupUi

    void retranslateUi(QMainWindow *C_CADRE)
    {
        C_CADRE->setWindowTitle(QApplication::translate("C_CADRE", "TEST_QT_CADRE", 0));
        action_Quitter->setText(QApplication::translate("C_CADRE", "&Quitter", 0));
        action_Test->setText(QApplication::translate("C_CADRE", "&Test", 0));
        action_Binaire->setText(QApplication::translate("C_CADRE", "&Binaire", 0));
        action_Hexa->setText(QApplication::translate("C_CADRE", "&Hexa", 0));
        action_Oct->setText(QApplication::translate("C_CADRE", "&Oct", 0));
        action_Decimal->setText(QApplication::translate("C_CADRE", "&Decimal", 0));
        pushButton->setText(QApplication::translate("C_CADRE", "Bouton", 0));
        menu_Fichier->setTitle(QApplication::translate("C_CADRE", "&Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class C_CADRE: public Ui_C_CADRE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_CADRE_H
