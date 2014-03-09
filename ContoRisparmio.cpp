#include "ContoRisparmio.h"
#include <string>
#include <sstream>
using std::string;

/**
 * @param nomeIntestatario
 * @param cognomeIntestatario
 * @param saldoIniziale
 */
ContoRisparmio::ContoRisparmio(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale) {}

ContoRisparmio::ContoRisparmio(const ContoRisparmio & cr): ContoBancario(cr) {}

/**

 * @param cifraPrelevata è la cifra da prelevare.
 */
double ContoRisparmio::preleva(double cifraPrelevata){
    //attenzione eccezione cifraPrelevata > 0
    if(cifraPrelevata <= getSaldo()){
        return ContoBancario::preleva(cifraPrelevata);
    } else {
        return ContoBancario::getSaldo();
    }
}

ContoRisparmio* ContoRisparmio::clona() const {
    return new ContoRisparmio(*this);
}

string ContoRisparmio::toString() const {
    std::stringstream dts;
    dts << getSaldo();
    return "ContoRisparmio: \n " + getNome() + " " + getCognome()
            + "\t SALDO: " + dts.str() + "\n";
}
