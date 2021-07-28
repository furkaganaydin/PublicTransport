#ifndef ANAEKRAN_H
#define ANAEKRAN_H
#include "biletalisekran.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AnaEkran; }
QT_END_NAMESPACE

class AnaEkran : public QMainWindow
{
    Q_OBJECT
public:
    AnaEkran(QWidget *parent = nullptr);
    ~AnaEkran();


private slots:
    void on_pushButton_clicked();

private:
    Ui::AnaEkran*ui;
    BiletAlisEkran*BiletAlis;
};
#endif // ANAEKRAN_H
