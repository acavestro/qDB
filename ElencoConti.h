#ifndef ELENCOCONTI_H
#define ELENCOCONTI_H
#include <Container.h>
#include <ContoBancario.h>
#include <ContoRisparmio.h>
#include <ContoCorrente.h>
#include <iostream>
using std::ostream;

class ElencoConti
{
    friend ostream& operator<<(ostream&, const ElencoConti&);
public:
    ElencoConti();
    void aggiungiConto(ContoBancario*);
    void aggiungiContoSeNonPresente(ContoBancario*);
private:
    class ContoPtr {
    public:
        ContoBancario* punt;
        ContoPtr(ContoBancario* =0);
        ContoPtr(const ContoPtr&);
        ~ContoPtr();
        ContoPtr& operator=(const ContoPtr&);
        bool operator==(const ContoPtr&) const;
        bool operator!=(const ContoPtr&) const;
        ContoBancario& operator*();
        const ContoBancario& operator*() const;
        ContoBancario* operator->();
        const ContoBancario* operator->() const;
    };

    Container<ContoPtr>* elenco;
};

#endif // ELENCOCONTI_H
