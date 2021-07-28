#include "sqlconnection.h"
#include "biletalisekran.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QtSql>



SQLConnection::SQLConnection()
{
   mydb = QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("C:/Users/karta/Desktop/Public transport project.db");
}
bool SQLConnection::connect()
{
    if(mydb.open())
        return true;
    else return false ;

}
void SQLConnection::disconnect()
{
    mydb.close();

}



