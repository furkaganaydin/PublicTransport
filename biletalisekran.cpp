#include "biletalisekran.h"
#include "ui_biletalisekran.h"
#include <QSqlDatabase>
#include <sqlconnection.h>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qdebug.h>
#include "anaekran.h"
#include <QSql>
#include <QSqlDriver>
#include <QDebug>
#include <QApplication>
#include <QCoreApplication>
#include <QSqlError>
#include <QSqlTableModel>



BiletAlisEkran::BiletAlisEkran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BiletAlisEkran)
{
    ui->setupUi(this);

    //Database Bağlantısı
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/karta/Desktop/proje1/Database.db");
    if(database.open()) {
        tableModel = new QSqlTableModel();
        tableModel->setTable("Station");
        tableModel->select();
        ui->Tablo1->setModel(tableModel);
    }else{
        QMessageBox::information(this,"Başarısız","Bağlantı Başarısız");
    }

    qDebug() << database.open();

       QSqlQueryModel *modal = new QSqlQueryModel();

       QSqlQuery* query = new QSqlQuery();
       query->prepare("SELECT * FROM Station Number");
       query->exec();

       modal->setQuery(*query);


       ui->Tablo1->setModel(modal);
       //practice_clients_db.close();

       //qDebug() << model->rowCount();

    ui->label_5->setText("Bilet Satış \n----------------------");
    ui->label_6->setText("Nereden:");
    ui->label_7->setText("Nereye:");
    ui->label_8->setText("Bilet Adeti:");
    ui->pushButton_8->setText("Bilet Al");
}

BiletAlisEkran::~BiletAlisEkran()
{
    delete ui;
}









void BiletAlisEkran::on_pushButton_clicked()
{
   QSqlQueryModel * modal = new QSqlQueryModel();
   connOpen();
   QSqlQuery* query = new QSqlQuery();
   query->prepare("SELECT * FROM Station Number");
   query->exec();
   modal->setQuery(*query);
   ui->Tablo1->setModel(modal);
   connclose();
   qDebug()<<(modal->rowCount());


}

