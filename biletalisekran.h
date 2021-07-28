#ifndef BILETALISEKRAN_H
#define BILETALISEKRAN_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlDriverPlugin>
#include <QtGui>
#include <QtCore>
#include <QDebug>
namespace Ui {
class BiletAlisEkran;
}

class BiletAlisEkran : public QDialog
{
    Q_OBJECT

public:
    explicit BiletAlisEkran(QWidget *parent = nullptr);
    ~BiletAlisEkran();



private slots:

public:
    QSqlDatabase database;
    void connclose(){
       database.close();
       database.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool connOpen(){

        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:/Users/karta/Desktop/proje1/AA.db");
        if(!database.open()){
            qDebug()<<("Failed the open database");
            return false;
        }
        else{
            qDebug()<<("Connected...");
            return true;
        }
    }

    void on_pushButton_clicked();

private:
    Ui::BiletAlisEkran *ui;

    QSqlTableModel*tableModel;
    QSqlQueryModel *model;

};

#endif // BILETALISEKRAN_H
