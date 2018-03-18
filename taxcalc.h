/*
-------------------------------------------------------------
Author: Trygve Sigurdsson Langfeldt
Studentnumber: s305106
-------------------------------------------------------------
*/

#ifndef TAXCALC_H
#define TAXCALC_H
#include <QPushButton>

class taxCalc
{
public:
 //------------------Inputs---------------------------
        int grossIncome;
        int capitalIncome;
        int bsuSavings;
        int netFortune;
        int interestAndCC;
        int distanceToWork;
        int labourFee;

 //------------------Calculate taxes------------------
    void calcTotalTax();

    //Get private members
    double getTopTax();
    double getSocialTax();
    double getGeneralTax();
    double getFortuneTax();
    double getTotalTax();
    double getBSUDed();

private:
 //------------------Outputs------------------
    int sumTopTax;
    int sumSocialTax;
    int sumGeneralTax;
    int sumFortuneTax;
    int totalSumTax;


 //------------------Functions------------------
    double topTaxAmount(int lvl, int salary);
    double topTaxSubAmount(int lvl);
    int topTaxlevel(double salary);

    double topTax();
    double socialTax();
    double generalTax();
    double fortuneTax();
    double totalTax();
    double bsuDeduction();

};

#endif // TAXCALC_H
