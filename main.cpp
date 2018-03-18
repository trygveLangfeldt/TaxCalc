#include "itax.h"
#include <QApplication>
/*
-------------------------------------------------------------
Author: Trygve Sigurdsson Langfeldt
Studentnumber: s305106
-------------------------------------------------------------
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iTax w;
    w.show();

    return a.exec();
}
