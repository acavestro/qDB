#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <ContoBancario.h>
#include <string>
using std::string;

class ContoCorrente: public ContoBancario
{
public:
    ContoCorrente(string, string, double = 0);
    ContoCorrente(const ContoCorrente&);
    //metodi virtuali
    double preleva(double);
    ContoCorrente* clona() const;
    string toString() const;

private:
    static double commissionePrelievo;
};

#endif // CONTOCORRENTE_H
