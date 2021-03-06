#include "ContoCorrente.h"
#include <sstream>


double ContoCorrente::commissionePrelievo = 0.5;
double ContoCorrente::commissioneDeposito = 0.01;

ContoCorrente::ContoCorrente(): ContoBancario() {}

/**
 * @param nomeIntestatario
 * @param cognomeIntestatario
 * @param saldoIniziale
 */
ContoCorrente::ContoCorrente(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale) {}

ContoCorrente::ContoCorrente(const ContoCorrente & cc): ContoBancario(cc) {}

double ContoCorrente::getCommissioneDeposito() {
    return commissioneDeposito;
}

double ContoCorrente::getCommissionePrelievo() {
    return commissionePrelievo;
}

/**
 * @param cifraPrelevata è la cifra da prelevare
 */
double ContoCorrente::preleva(double cifraPrelevata){
    return ContoBancario::preleva(cifraPrelevata + commissionePrelievo);
}

/**
 * @param cifraDepositata è la cifra da depositare
 */
double ContoCorrente::deposita(double cifraDepositata){
    return ContoBancario::deposita(cifraDepositata - commissioneDeposito);
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

bool ContoCorrente::operator ==(const ContoBancario& cb) const {
    const ContoCorrente* cc = dynamic_cast<const ContoCorrente*>(&cb);
    if(cc && ContoBancario::operator ==(cb))
        return true;
    else
        return false;
}

string ContoCorrente::getTipoConto() const {
    return "Conto Corrente";
}
