/*
-------------------------------------------------------------
Author: Trygve Sigurdsson Langfeldt
Studentnumber: s305106
-------------------------------------------------------------
*/


#include "itax.h"
#include "taxcalc.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>

iTax::iTax(QWidget *parent)
    : QWidget(parent)
{
//------------Labels-------------------------------
incomeLabel= new QLabel(tr("Din brutto årslønn"));
capitalLabel= new QLabel(tr("Kapitalinntekter"));
distanceLabel=new QLabel(tr("Avstand til arbeidssted(en vei)"));
interestCCLabel=new QLabel(tr("Renter og kapitalkostnader"));
bsuLabel =new QLabel(tr("Sparing i BSU"));
unionLabel= new QLabel(tr("Faforeningskontigent"));
netFortuneLabel= new QLabel(tr("Samlet netto formue"));


topTaxLabel= new QLabel(tr("Toppskatt/trinnskatt"));
socialTaxLabel= new QLabel(tr("Trygdeavgift"));
generalTaxLabel= new QLabel(tr("Fellesskatt"));
fortuneTaxLabel= new QLabel(tr("Formueskatt"));
bsuDedLabel = new QLabel(tr("BSU fradrag"));
totalTaxLabel= new QLabel(tr("Sum skatt"));


//-----Spinbox group - inputs---------------
incomeSpinBox= new QSpinBox;
incomeSpinBox->setRange(0,200000000); //I put the maxvalue to 200.000.000, not sure how to set unlimited
incomeSpinBox->setSingleStep(1000);
incomeSpinBox->setValue(490000);


capitalSpinBox = new QSpinBox;
capitalSpinBox ->setRange(0,200000000);
capitalSpinBox ->setSingleStep(1000);
capitalSpinBox -> setValue(0);


distanceSpinBox = new QSpinBox;
distanceSpinBox ->setRange(0,200000000);
distanceSpinBox->setSingleStep(1);
distanceSpinBox->setValue(0);


interestCCSpinBox = new QSpinBox;
interestCCSpinBox ->setRange(0,200000000);
interestCCSpinBox ->setSingleStep(1000);
interestCCSpinBox ->setValue(0);


bsuSpinBox = new QSpinBox;
bsuSpinBox ->setRange(0,200000000);
bsuSpinBox->setSingleStep(500);
bsuSpinBox -> setValue(0);


unionSpinbox = new QSpinBox;
unionSpinbox->setRange(0,200000000);
unionSpinbox->setSingleStep(10);
unionSpinbox ->setValue(0);



netForuneSpinBox = new QSpinBox;
netForuneSpinBox ->setRange(0,200000000);
netForuneSpinBox ->setSingleStep(1000);
netForuneSpinBox ->setValue(0);



//----- LineEdit group - Outputs--------------------------------
topTaxLine = new QLineEdit;
topTaxLine->setEnabled(false);

socialTaxLine = new QLineEdit;
socialTaxLine->setEnabled(false);

generalTaxLine = new QLineEdit;
generalTaxLine->setEnabled(false);

fortuneTaxLine = new QLineEdit;
fortuneTaxLine->setEnabled(false);

bsuDedLine = new QLineEdit;
bsuDedLine->setEnabled(false);

totalTaxLine = new QLineEdit;
totalTaxLine->setEnabled(false);

//---------Button -----------------------
calcButton = new QPushButton(tr("Beregn!"));
// When button is pushed the function setAndCalc() will run
connect(calcButton,SIGNAL(released()),this,SLOT(setAndCalc()));

//--------------Layout group-------------------
int i = 1; //Variables used to design the layout of the QT app
int r = 1;//  Not really nececary, but I wanted it to be easy
int d = 1;// to ajust the size of the spinboxes, labels and space between them


//_____________Inputs___________________________
QHBoxLayout *incomeRow = new QHBoxLayout;
incomeRow->addWidget(incomeLabel,r);
incomeRow->addStretch(d);
incomeRow->addWidget(incomeSpinBox,i);

QHBoxLayout * ccRow = new QHBoxLayout;
ccRow->addWidget(capitalLabel,r);
ccRow->addStretch(d);
ccRow->addWidget(capitalSpinBox,i);

QHBoxLayout *distanceRow = new QHBoxLayout;
distanceRow->addWidget(distanceLabel,r);
distanceRow->addStretch(d);
distanceRow->addWidget(distanceSpinBox,i);


QHBoxLayout *interestCCRow = new QHBoxLayout;
interestCCRow->addWidget(interestCCLabel,r);
interestCCRow->addStretch(d);
interestCCRow->addWidget(interestCCSpinBox,i);


QHBoxLayout *bsuRow = new QHBoxLayout;
bsuRow->addWidget(bsuLabel,r);
bsuRow->addStretch(d);
bsuRow->addWidget(bsuSpinBox,i);


QHBoxLayout *unionRow = new QHBoxLayout;
unionRow->addWidget(unionLabel,r);
unionRow->addStretch(d);
unionRow->addWidget(unionSpinbox,i);


QHBoxLayout *netFortuneRow = new QHBoxLayout;
netFortuneRow->addWidget(netFortuneLabel,r);
netFortuneRow->addStretch(d);
netFortuneRow->addWidget(netForuneSpinBox,i);

//_____________Outputs_________________________
QHBoxLayout *topTaxRow = new QHBoxLayout;
topTaxRow->addWidget(topTaxLabel,r);
topTaxRow->addStretch(d);
topTaxRow->addWidget(topTaxLine,i);

QHBoxLayout *socialRow = new QHBoxLayout;
socialRow->addWidget(socialTaxLabel,r);
socialRow->addStretch(d);
socialRow->addWidget(socialTaxLine,i);

QHBoxLayout *generalTaxRow = new QHBoxLayout;
generalTaxRow->addWidget(generalTaxLabel,r);
generalTaxRow->addStretch(d);
generalTaxRow->addWidget(generalTaxLine,i);

QHBoxLayout *fortuneTaxRow = new QHBoxLayout;
fortuneTaxRow->addWidget(fortuneTaxLabel,r);
fortuneTaxRow->addStretch(d);
fortuneTaxRow->addWidget(fortuneTaxLine,i);

QHBoxLayout *bsuDedRow = new QHBoxLayout;
bsuDedRow->addWidget(bsuDedLabel,r);
bsuDedRow->addStretch(d);
bsuDedRow->addWidget(bsuDedLine,i);

QHBoxLayout *totalTaxRow = new QHBoxLayout;
totalTaxRow->addWidget(totalTaxLabel,r);
totalTaxRow->addStretch(d);
totalTaxRow->addWidget(totalTaxLine,i);

/*-------------Groups------------------
I decided to group the inputs and outputs to make the design look better. Not sure if this is the
most efficient way to do this but it worked.
*/
QVBoxLayout *inputsGroup = new QVBoxLayout;
inputsGroup->addLayout(incomeRow);
inputsGroup->addLayout(ccRow);
inputsGroup->addLayout(distanceRow);
inputsGroup->addLayout(bsuRow);
inputsGroup->addLayout(interestCCRow);
inputsGroup->addLayout(unionRow);
inputsGroup->addLayout(netFortuneRow);

QVBoxLayout *outputsGroup = new QVBoxLayout;
outputsGroup->addLayout(topTaxRow);
outputsGroup->addLayout(socialRow);
outputsGroup->addLayout(generalTaxRow);
outputsGroup->addLayout(fortuneTaxRow);
outputsGroup->addLayout(bsuDedRow);
outputsGroup->addLayout(totalTaxRow);


QVBoxLayout *buttonsGroup = new QVBoxLayout;
buttonsGroup->addWidget(calcButton);


//------------Group box----------------------------
QGroupBox *IGroup = new QGroupBox; //Inputs group
IGroup->setLayout(inputsGroup);
QGroupBox *OGroup = new QGroupBox; // Outputs group
OGroup->setLayout(outputsGroup);

QGroupBox *BGroup = new QGroupBox; //Button group
BGroup->setLayout(buttonsGroup);


QGridLayout *grid = new QGridLayout;
grid->addWidget(IGroup);
grid->addWidget(OGroup);
grid->addWidget(BGroup);

setWindowTitle(tr("Personlig Skattekalkulator - s305106"));
setGeometry(500,200,500,400);
setLayout(grid);

}

iTax::~iTax()
{

}
void iTax::setAndCalc()
{
    //All variables wil be set to the inheritted class
    netFortune = netForuneSpinBox->value();
    labourFee = unionSpinbox->value();
    bsuSavings = bsuSpinBox->value();
    interestAndCC = interestCCSpinBox->value();
    distanceToWork = distanceSpinBox->value();
    grossIncome = incomeSpinBox->value();
    capitalIncome = capitalSpinBox->value();


    calcTotalTax(); //Run the calculating function

    //Retrieving calculate
    topTaxLine->setText(QString::number(getTopTax()));
    socialTaxLine->setText(QString::number(getSocialTax()));
    generalTaxLine->setText(QString::number(getGeneralTax()));
    fortuneTaxLine->setText(QString::number(getFortuneTax()));
    bsuDedLine->setText(QString::number(getBSUDed()));
    totalTaxLine->setText(QString::number(getTotalTax()));
}
