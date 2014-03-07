#include "ContoCorrente.h"
#include <sstream>
using std::string;

double ContoCorrente::commissionePrelievo = 0.5;

ContoCorrente::ContoCorrente(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale) {}

ContoCorrente::ContoCorrente(const ContoCorrente & cc): ContoBancario(cc) {}

double ContoCorrente::preleva(double cifraPrelevata){
    //da gestire eccezione: cifraPrelevata > 0
    return ContoBancario::preleva(cifraPrelevata - commissionePrelievo);
}

//restituisce una copia dell'oggetto d'instanza
//allocato sullo heap. ATTENZIONE AL GARBAGE!
ContoCorrente* ContoCorrente::clona() const {
    return new ContoCorrente(*this);
}

string ContoCorrente::toString() const {
    std::stringstream dts, cts;
    dts << getSaldo();
    cts << commissionePrelievo;
    return "ContoCorrente (Prelievo: " + cts.str() + "): \n " +
            getNome() + " " + getCognome() + "\t SALDO: " +
            dts.str() + "\n";
}
