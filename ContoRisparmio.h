#ifndef CONTORISPARMIO_H
#define CONTORISPARMIO_H
#include <ContoBancario.h>
#include <string>
using std::string;

class ContoRisparmio: public ContoBancario
{
public:
    ContoRisparmio(string, string, double = 0);
    ContoRisparmio(const ContoRisparmio&);
    //metodi virtuali
    double preleva(double);
    ContoRisparmio* clona() const;
};

#endif // CONTORISPARMIO_H
