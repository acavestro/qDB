#include "ContoRisparmio.h"
#include <string>
ContoRisparmio::ContoRisparmio(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale) {}

ContoRisparmio::ContoRisparmio(const ContoRisparmio & cr): ContoBancario(cr) {}

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
