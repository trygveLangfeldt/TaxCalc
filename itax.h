/*
-------------------------------------------------------------
Author: Trygve Sigurdsson Langfeldt
Studentnumber: s305106
-------------------------------------------------------------
*/


#ifndef ITAX_H
#define ITAX_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <taxcalc.h>


class iTax :
        public QWidget,
        public taxCalc
{
    Q_OBJECT

public:
    iTax(QWidget *parent = 0);
    ~iTax();
private:

//----------Inputs--------------------------

QLabel *incomeLabel;
QSpinBox *incomeSpinBox;

QLabel *capitalLabel;
QSpinBox *capitalSpinBox;

QLabel *distanceLabel;
QSpinBox *distanceSpinBox;

QLabel *interestCCLabel;
QSpinBox *interestCCSpinBox;

QLabel *bsuLabel;
QSpinBox *bsuSpinBox;

QLabel *unionLabel;
QSpinBox *unionSpinbox;

QLabel *netFortuneLabel;
QSpinBox *netForuneSpinBox;

//-----------Outputs----------------

QLabel *topTaxLabel;
QLineEdit *topTaxLine;

QLabel *socialTaxLabel;
QLineEdit *socialTaxLine;

QLabel *generalTaxLabel;
QLineEdit *generalTaxLine;

QLabel *fortuneTaxLabel;
QLineEdit *fortuneTaxLine;

QLabel *bsuDedLabel;
QLineEdit *bsuDedLine;

QLabel *totalTaxLabel;
QLineEdit *totalTaxLine;

QPushButton *calcButton;



private slots:
void setAndCalc();

};

#endif // ITAX_H
