#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include <QSqlDatabase>
#include <biletalisekran.h>
#include <QSqlTableModel>
#include <QtSql>
#include <QMainWindow>
#include <biletalisekran.h>
namespace Ui {
class SQLConnection;
}

class SQLConnection : public QMainWindow
{
    Q_OBJECT

public:
    explicit SQLConnection(QWidget *parent = nullptr);
    ~SQLConnection();

    QSqlDatabase mydb;

    bool openDB(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/karta/Desktop/Public transport project.db");

        if(!mydb.open())
        {
            qDebug()<<"Error opening database" << mydb.lastError();
            return false;
        }else{
            qDebug()<<"Connection Established.";
            return true;
        }
    }

    void closeDB(){
        mydb.close();
        //db.removeDatabase(QSqlDatabase::defaultConnection);
    }



private:
    Ui::SQLConnection *ui;



public:
    SQLConnection();
    bool connect();
    void disconnect();

};
#endif // SQLCONNECTION_H



