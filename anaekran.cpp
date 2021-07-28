#include "anaekran.h"
#include "ui_anaekran.h"
#include "biletalisekran.h"
#include "sqlconnection.h"
#include <QDebug>
AnaEkran::AnaEkran(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnaEkran)
{

    ui->setupUi(this);
    ui->label->setText("İslem Tipini Seçiniz : ...");
    ui->label_2->setText("Ana Ekran \n-------------------------------------------");
    ui->pushButton->setText("1-Bilet alım ");
    ui->pushButton_2->setText("2-Bilet İade ");

}

AnaEkran::~AnaEkran()
{
    delete ui;
}


void AnaEkran::on_pushButton_clicked()
{
    hide();
    BiletAlis = new BiletAlisEkran(this);
    BiletAlis->show();
}

