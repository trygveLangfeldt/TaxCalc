/*
-------------------------------------------------------------
Author: Trygve Sigurdsson Langfeldt
Studentnumber: s305106
-------------------------------------------------------------
*/
#include "taxcalc.h"
#include <iostream>

//---------Calcucations of taxs and deductions---------
double taxCalc::socialTax()
{
    static int const freeCard= 54650;
    double sTax;


    if (grossIncome>freeCard)
    {
        sTax = grossIncome*0.082;
        static double maxSTax = 0.25*(grossIncome - freeCard);
        if (sTax>maxSTax)
        {
            sTax = maxSTax;
        }
    }
    else
    {
        sTax = 0;
    }

    return sTax;
}

double taxCalc::topTax()
{

    int taxLvl = topTaxlevel(grossIncome);
    double subtaxAmt = topTaxSubAmount(taxLvl);
    double taxAmt = topTaxAmount(taxLvl, grossIncome);
    return taxAmt + subtaxAmt;

}

double taxCalc::generalTax()
{
    // Taxable amount = Capital income + gross income - person deduction
    //- minimum deduction - worktravel deduction - labor ded - capitalcost ded
    static int const pDeduction = 54750;
    static int minDeduction = grossIncome*0.45;
    if (minDeduction<4000)
    {
        minDeduction = 4000;
    }
    else if (minDeduction > 97610)
    {
        minDeduction = 97610;
    }

    static double wTravelDed;
    static int const wDays = 230;
    static double const high = 1.56;
    static double const low = 0.76;
    if (distanceToWork*230>50000)
    {
        wTravelDed = 2 * distanceToWork*low*wDays;
    }
    else
    {
        wTravelDed = 2 * distanceToWork*high*wDays;
    }
    wTravelDed=wTravelDed - 22350;
    if(wTravelDed<0) wTravelDed = 0;

    static double labourDed;
    if (labourFee > 3850)
    {
        labourDed = 3850;
    }
    else
    {
        labourDed = labourFee;
    }


    double netSalary = grossIncome+capitalIncome - pDeduction -
            minDeduction - wTravelDed - labourDed - interestAndCC;

    double gTax = 0.23*netSalary;

        if (gTax<=0)
        {
            gTax = 0;
        }

    return gTax;
}

double taxCalc::fortuneTax()
{

    static double cTax = 0 ;
    static double sTax = 0 ;

    static int maxF = 1480000 ;


    if (netFortune > maxF)
    {
        cTax = (netFortune - maxF)*0.7/100;
        sTax = (netFortune- maxF)*0.15/100;
    }

    double fTax = cTax + sTax;

    return fTax;

}

double taxCalc::bsuDeduction()
{
    static double bsuDed;

    if (bsuSavings>25000)
    {
        bsuDed = 25000 * 0.2;
    }
    else
    {
        bsuDed = bsuSavings*0.2;
    }
    return bsuDed;
}

//---------Calculate all taxes and set to private variables---------
void taxCalc::calcTotalTax()
{
    sumTopTax = topTax();
    sumSocialTax = socialTax();
    sumGeneralTax = generalTax();
    sumFortuneTax = fortuneTax();
    totalSumTax = sumTopTax + sumSocialTax + sumGeneralTax + sumFortuneTax - bsuDeduction();
}


//---------Get taxes and deductions from private members---------

double taxCalc::getTopTax()
{
    return sumTopTax;
}

double taxCalc::getSocialTax()
{
    return sumSocialTax;
}

double taxCalc::getGeneralTax()
{
    return sumGeneralTax;
}

double taxCalc::getFortuneTax()
{
    return sumFortuneTax;
}

double taxCalc::getTotalTax()
{
    return totalSumTax;
}

double taxCalc::getBSUDed(){

    return -bsuDeduction();
}


//---------Other functions(from TopTax coursework 2)---------

double taxCalc::topTaxAmount(int lvl, int salary)
{
    static int const  lvl2 =169000;
    static int const lvl3 = 237900;
    static int const lvl4 =598050;
    static int const lvl5 = 962050;

    static double const lvlPrc2= 1.4 ;
    static double const lvlPrc3= 3.3;
    static double const lvlPrc4= 12.4;
    static double const lvlPrc5= 15.4;
    int tax;

    if(lvl == 1) tax = 0;
    if(lvl == 2)tax = (salary - lvl2)*lvlPrc2 / 100;
    if(lvl == 3) tax = (salary - lvl3)*lvlPrc3 / 100;
    if(lvl ==4) tax = (salary - lvl4)*lvlPrc4 / 100;
    if(lvl ==5) tax = (salary - lvl5)*lvlPrc5 / 100;

    return tax;

}

double taxCalc::topTaxSubAmount(int lvl)
{
     static int const lvlAmt1 = 0;
     static int const lvlAmt2 = 965; // (lvl3 - lvl2)*lvlPrc1/100
     static int const lvlAmt3 = 11885;// (lvl4 - lvl3)*lvlPrc2/100
     static int const lvlAmt4 = 45136;// (lvl5 - lvl4)*lvlPrc3/100

    switch (lvl)
    {
    case 1:
        return lvlAmt1;
    case 2:

        return lvlAmt1;
    case 3:
        return lvlAmt2;

    case 4:
        return lvlAmt2 + lvlAmt3;

    case 5:
        return lvlAmt2 + lvlAmt3 + lvlAmt4;
    default:
        break;
    }
}

int taxCalc::topTaxlevel(double salary)
{
    static int const  lvl2 =169000;
    static int const lvl3 = 237900;
    static int const lvl4 =598050;
    static int const lvl5 = 962050;

    if (salary <= lvl2)
    {
        return 1;
    }
    else if (salary > lvl2 && salary <= lvl3)
    {
        return 2;
    }
    else if (salary > lvl3 && salary <= lvl4)
    {
        return 3;
    }
    else if (salary >lvl4 && salary <= lvl5)
    {
        return 4;
    }
    else if (salary > lvl5)
    {
        return 5;
    }

}

