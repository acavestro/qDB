#include "mainwindow.h"
#include <QApplication>
#include <CBPpointer.h>
#include <ContoCorrente.h>
#include <ContoRisparmio.h>
#include <Container.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */

    Container<CBPointer>* elenco = new Container<CBPointer>();
    CBPointer c1 = new ContoRisparmio("Mario", "Rossi");
    elenco->addItem(c1);
    CBPointer c2 = new ContoCorrente("Paolo", "Bianchi", 1000);
    elenco->addItem(c2);

    for(Container<CBPointer>::ConstIterator i = elenco->begin(); i != elenco->end(); i++){
        cout << (*elenco)[i]->getCognome() << " " << (*elenco)[i]->getNome() << endl;
        cout << "SALDO: " << (*elenco)[i]->getSaldo() << endl;
    }

}
