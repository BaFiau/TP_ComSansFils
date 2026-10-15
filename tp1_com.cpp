#include "tp1_com.h"
#include "Sw_Mf_Classic.h"
#include "ui_tp1_com.h"
#include "MfErrNo.h"
#include "Sw_Device.h"
#include <QDebug>
#include "Librairie.h"
#include "Sw_ISO14443A-3.h"
#include "TypeDefs.h"
#include "Hardware.h"

TP1_Com::TP1_Com(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TP1_Com)
{
    ui->setupUi(this);
}

TP1_Com::~TP1_Com()
{
    delete ui;
}

ReaderName MonLecteur;
uint8_t atq[2];
uint8_t sak[1];
uint8_t uid[10];
uint16_t uid_len =10;

void TP1_Com::on_Connect_clicked()
{
    int16_t status = MI_OK;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = OpenCOM(&MonLecteur);
    qDebug() << "OpenCOM" << status;
    status = Version(&MonLecteur);
    RF_Power_Control(&MonLecteur, true, 1);
    ui->Affiche->setText(MonLecteur.version);
    ui->Affiche->update();
}


void TP1_Com::on_Disconnect_clicked()
{
    int16_t status = MI_OK;
    RF_Power_Control(&MonLecteur, FALSE, 0);
    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    qApp->quit();
}


void TP1_Com::on_Selection_clicked()
{
    int16_t status;
    uint8_t nom[16];
    uint8_t prenom[16];
    uint32_t compteur = 0;
    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 10, nom,AuthKeyA ,2);
    if (status == MI_OK) {
        //QString n = QString::fromLocal8Bit((char*)nom);
        ui->Affiche_Nom->setText((char*)nom);
        }
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, prenom ,AuthKeyA ,2);
    if (status == MI_OK) {
        ui->Affiche_Prenom->setText((char*)prenom);
    }
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &compteur ,AuthKeyA ,3);
    if (status == MI_OK) {
        ui->Affiche_Compteur->setText(QString::number(compteur));
    }
}


void TP1_Com::on_Mise_a_jour_clicked()
{
    int16_t status;
    uint8_t nom[16];
    uint8_t prenom[16];
    //QString Text = ui->Affiche_Nom->toPlainText();
    //uint8_t val[16] = static_cast<uint8_t>(Text.toUInt());
    char DataIn[16];
    strncpy(DataIn, ui->Affiche_Prenom->toPlainText().toUtf8().data(), 16);

    char DataIn1[16];
    strncpy(DataIn1, ui->Affiche_Nom->toPlainText().toUtf8().data(), 16);


    status = Mf_Classic_Write_Block(&MonLecteur, TRUE,10,(uint8_t*)DataIn1,AuthKeyB, 2 );
    status = Mf_Classic_Write_Block(&MonLecteur, TRUE,9, (uint8_t *)DataIn,AuthKeyB, 2 );
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 10, nom,AuthKeyA ,2);
    if (status == MI_OK) {
        //QString n = QString::fromLocal8Bit((char*)nom);
        ui->Affiche_Nom->setText((char*)nom);
    }
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, prenom ,AuthKeyA ,2);
    if (status == MI_OK) {
        ui->Affiche_Prenom->setText((char*)prenom);
    }
}




void TP1_Com::on_Charger_clicked()
{
    int16_t status;
    uint32_t compteur = 0;
    uint32_t val = ui->Affiche_Charger->value();
    status = Mf_Classic_Increment_Value(&MonLecteur,TRUE,14,val,14,AuthKeyB,3);
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &compteur ,AuthKeyA ,3);
    if (status == MI_OK) {
        ui->Affiche_Compteur->setText(QString::number(compteur));
    }
}


void TP1_Com::on_Payer_clicked()
{
    int16_t status;
    uint32_t compteur = 0;
    uint32_t val = ui->Affiche_Payer->value();
    status = Mf_Classic_Decrement_Value(&MonLecteur,TRUE,14,val,14,AuthKeyB,3);
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &compteur ,AuthKeyA ,3);
    if (status == MI_OK) {
        ui->Affiche_Compteur->setText(QString::number(compteur));
    }
}

