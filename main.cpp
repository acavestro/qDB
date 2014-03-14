#include "mainwindow.h"
#include <QApplication>
#include "QString"
#include "QTextCodec"


int main(int argc, char *argv[])
{
    /*
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
    */

    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();

    return a.exec();


}
