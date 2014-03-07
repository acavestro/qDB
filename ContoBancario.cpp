#include "ContoBancario.h"
#include <string>
#include <sstream>
using std::string;

ContoBancario::ContoBancario(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale):
    saldo(saldoIniziale), nome(nomeIntestatario), cognome(cognomeIntestatario) {}

ContoBancario::ContoBancario(const ContoBancario & cb):
    saldo(cb.saldo), nome(cb.nome), cognome(cb.cognome) {}

ContoBancario::~ContoBancario() {}

double ContoBancario::preleva(double cifraPrelevata){
    //da gestire eccezione: cifraPrelevata > 0
    saldo -= cifraPrelevata;
    return saldo;
}

double ContoBancario::deposita(double cifraDepositata){
    //da gestire eccezione: cifraDepositata > 0
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

void ContoBancario::setNome(string newNome) {
    //da gestire eccezione newNome non vuoto
    nome = newNome;
}

void ContoBancario::setCognome(string newCognome) {
    //da gestire eccezione newCognome non vuoto
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
