#include "ContoRisparmio.h"
#include <string>
#include <sstream>
using std::string;

ContoRisparmio::ContoRisparmio(): ContoBancario() {}

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

bool ContoRisparmio::operator ==(const ContoBancario& cb) const {
    const ContoRisparmio* cr = dynamic_cast<const ContoRisparmio*>(&cb);
    if(cr && ContoBancario::operator ==(cb))
        return true;
    else
        return false;
}

string ContoRisparmio::getTipoConto() const {
    return "Conto Risparmio";
}
