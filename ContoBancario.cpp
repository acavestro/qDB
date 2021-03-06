#include "ContoBancario.h"
#include <sstream>


ContoBancario::ContoBancario(): saldo(0), nome("Utente"), cognome("Non Identificato"){}

/**
 * @param nomeIntestatario
 * @param cognomeIntestatario
 * @param saldoIniziale
 */
ContoBancario::ContoBancario(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    saldo(saldoIniziale), nome(nomeIntestatario), cognome(cognomeIntestatario) {}

ContoBancario::ContoBancario(const ContoBancario & cb):
    saldo(cb.saldo), nome(cb.nome), cognome(cb.cognome) {}

ContoBancario::~ContoBancario() {}

/**
 * @param cifraPrelevata è il valore da prelevare.
 */
double ContoBancario::preleva(double cifraPrelevata){
    saldo -= cifraPrelevata;
    return saldo;
}

/**
 * @param cifraDepositata è il valore da depositare.
 */
double ContoBancario::deposita(double cifraDepositata){
    saldo += cifraDepositata;
    return saldo;
}

double ContoBancario::getSaldo() const {
    return saldo;
}

string ContoBancario::getNome() const {
    return nome;
}

string ContoBancario::getCognome() const {
    return cognome;
}

/**
 * @param newNome è il nuovo nome dell'intestatario
 */
void ContoBancario::setNome(string newNome) {
    nome = newNome;
}

/**
 * @param newCognome è il nuovo cognome dell'intestatario
 */
void ContoBancario::setCognome(string newCognome) {
    cognome = newCognome;
}

//restituisce una copia dell'oggetto d'istanza
//allocata sullo heap. ATTENZIONE AL GARBAGE!
ContoBancario* ContoBancario::clona() const {
    return new ContoBancario(*this);
}

string ContoBancario::toString() const {
    std::stringstream dts;
    dts << saldo;
    string s = "ContoBancario: \n " + nome + " " + cognome +
            "\t SALDO: " + dts.str() + "\n";
    return s;
}

bool ContoBancario::operator ==(const ContoBancario& cb) const {
    return nome == cb.nome && cognome == cb.cognome && saldo == cb.saldo;
}

string ContoBancario::getTipoConto() const {
    return "Conto Bancario";
}
