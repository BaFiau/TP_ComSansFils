/********************************************************************************
** Form generated from reading UI file 'tp1_com.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP1_COM_H
#define UI_TP1_COM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TP1_Com
{
public:
    QWidget *centralwidget;
    QPushButton *Disconnect;
    QPushButton *Connect;
    QTextEdit *Affiche;
    QTextEdit *Affiche_Nom;
    QPushButton *Selection;
    QTextEdit *Affiche_Prenom;
    QTextEdit *Affiche_Compteur;
    QPushButton *Mise_a_jour;
    QSpinBox *Affiche_Charger;
    QSpinBox *Affiche_Payer;
    QPushButton *Charger;
    QPushButton *Payer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TP1_Com)
    {
        if (TP1_Com->objectName().isEmpty())
            TP1_Com->setObjectName("TP1_Com");
        TP1_Com->resize(800, 600);
        centralwidget = new QWidget(TP1_Com);
        centralwidget->setObjectName("centralwidget");
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName("Disconnect");
        Disconnect->setGeometry(QRect(40, 320, 81, 31));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName("Connect");
        Connect->setGeometry(QRect(50, 40, 81, 41));
        Affiche = new QTextEdit(centralwidget);
        Affiche->setObjectName("Affiche");
        Affiche->setGeometry(QRect(160, 30, 104, 66));
        Affiche_Nom = new QTextEdit(centralwidget);
        Affiche_Nom->setObjectName("Affiche_Nom");
        Affiche_Nom->setGeometry(QRect(180, 130, 104, 21));
        Selection = new QPushButton(centralwidget);
        Selection->setObjectName("Selection");
        Selection->setGeometry(QRect(20, 130, 141, 41));
        Affiche_Prenom = new QTextEdit(centralwidget);
        Affiche_Prenom->setObjectName("Affiche_Prenom");
        Affiche_Prenom->setGeometry(QRect(180, 160, 111, 21));
        Affiche_Compteur = new QTextEdit(centralwidget);
        Affiche_Compteur->setObjectName("Affiche_Compteur");
        Affiche_Compteur->setGeometry(QRect(180, 190, 91, 31));
        Mise_a_jour = new QPushButton(centralwidget);
        Mise_a_jour->setObjectName("Mise_a_jour");
        Mise_a_jour->setGeometry(QRect(20, 190, 121, 31));
        Affiche_Charger = new QSpinBox(centralwidget);
        Affiche_Charger->setObjectName("Affiche_Charger");
        Affiche_Charger->setGeometry(QRect(190, 240, 71, 31));
        Affiche_Payer = new QSpinBox(centralwidget);
        Affiche_Payer->setObjectName("Affiche_Payer");
        Affiche_Payer->setGeometry(QRect(190, 280, 71, 41));
        Charger = new QPushButton(centralwidget);
        Charger->setObjectName("Charger");
        Charger->setGeometry(QRect(30, 240, 121, 21));
        Payer = new QPushButton(centralwidget);
        Payer->setObjectName("Payer");
        Payer->setGeometry(QRect(30, 280, 121, 21));
        TP1_Com->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TP1_Com);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        TP1_Com->setMenuBar(menubar);
        statusbar = new QStatusBar(TP1_Com);
        statusbar->setObjectName("statusbar");
        TP1_Com->setStatusBar(statusbar);

        retranslateUi(TP1_Com);

        QMetaObject::connectSlotsByName(TP1_Com);
    } // setupUi

    void retranslateUi(QMainWindow *TP1_Com)
    {
        TP1_Com->setWindowTitle(QCoreApplication::translate("TP1_Com", "TP1_Com", nullptr));
        Disconnect->setText(QCoreApplication::translate("TP1_Com", "Disconnect", nullptr));
        Connect->setText(QCoreApplication::translate("TP1_Com", "Connect", nullptr));
        Selection->setText(QCoreApplication::translate("TP1_Com", "Selection de la carte", nullptr));
        Mise_a_jour->setText(QCoreApplication::translate("TP1_Com", "Mise \303\240 Jour", nullptr));
        Charger->setText(QCoreApplication::translate("TP1_Com", "Charger", nullptr));
        Payer->setText(QCoreApplication::translate("TP1_Com", "Payer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP1_Com: public Ui_TP1_Com {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP1_COM_H
