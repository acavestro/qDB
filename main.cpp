#include "mainwindow.h"
#include <QApplication>
#include <ElencoConti.h>
#include <iostream>
#include <string>
#include <ContoRisparmio.h>
#include <ContoCorrente.h>
using namespace std;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */

    ElencoConti elenco;
    elenco.aggiungiConto(new ContoRisparmio("Mario", "Rossi"));
    elenco.aggiungiConto(new ContoCorrente("Paolo", "Bianchi", 1000));
    elenco.aggiungiConto(new ContoCorrente("Mario", "Bianchi", 10000));
    cout << elenco;

}
