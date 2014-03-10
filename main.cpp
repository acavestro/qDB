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
    elenco.addAccount(new ContoRisparmio("Mario", "Rossi"));
    elenco.addAccount(new ContoCorrente("Paolo", "Bianchi", 1000));
    elenco.addAccount(new ContoCorrente("Mario", "Bianchi", 10000));
    elenco.addAccountIfNotPresent(new ContoRisparmio("Mario", "Rossi"));
    elenco.addAccountIfNotPresent(new ContoRisparmio("Francesco", "Papa", 50000));
    cout << elenco;
    cout << endl;
    ElencoConti::ContoPtr* c = elenco.searchSingleAccount("*", "*", "<=", 1000);
    if (c != 0)
        cout << (*c)->getNome() << " " << (*c)->getCognome() << " " << (*c)->getSaldo() << endl;
    else
        cout << "Account non trovato";
    cout << endl;
    cout << elenco;

}
