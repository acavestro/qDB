#include "ElencoConti.h"

ElencoConti::ElencoConti(): elenco(new Container<ContoPtr>){}

ElencoConti::~ElencoConti(){
    delete elenco;
}


void ElencoConti::addNewContoBancario(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    elenco->push_back(new ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale));
}

void ElencoConti::addNewContoBancarioIfNotPresent(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    ContoPtr p = new ContoBancario(nomeIntestatario, cognomeIntestatario, saldoIniziale);
    if(!elenco->contains(p))
        elenco->push_back(p);
}

void ElencoConti::addNewContoCorrente(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    elenco->push_back(new ContoCorrente(nomeIntestatario, cognomeIntestatario, saldoIniziale));
}

void ElencoConti::addNewContoCorrenteIfNotPresent(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    ContoPtr p = new ContoCorrente(nomeIntestatario, cognomeIntestatario, saldoIniziale);
    if(!elenco->contains(p))
        elenco->push_back(p);
}

void ElencoConti::addNewContoRisparmio(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    elenco->push_back(new ContoRisparmio(nomeIntestatario, cognomeIntestatario, saldoIniziale));
}

void ElencoConti::addNewContoRisparmioIfNotPresent(string nomeIntestatario, string cognomeIntestatario, double saldoIniziale){
    ContoPtr p = new ContoRisparmio(nomeIntestatario, cognomeIntestatario, saldoIniziale);
    if(!elenco->contains(p))
        elenco->push_back(p);
}

/**
 * @param cb è il conto da cancellare
 */
void ElencoConti::deleteAccount(ContoPtr& cb){
    elenco->removeElement(cb);
}

/**
 * @param it è l'iteratore dell'elemento da rimuovere
 */
void ElencoConti::deleteAccount(Container<ContoPtr>::Iterator it){
    elenco->removeElementAt(it);
}


/**
 * @param namePattern è il nome da cercare (o *)
 * @param surnamePattern è il cognome da cercare (o *)
 * @param balancePattern è il pattern del saldo (=, >, >=, <, <=)
 * @param balanceValue è il valore su cui applicare il pattern del saldo
 */
Container<Container<ElencoConti::ContoPtr>::Iterator> ElencoConti::search(string namePattern,
                                                      string surnamePattern,
                                                      string balancePattern,
                                                      double balanceValue) const {


    Container<Container<ElencoConti::ContoPtr>::Iterator> c;
    for(int i = 0; i < elenco->getSize(); i++){
        if((*elenco)[i].hasThisName(namePattern) &&
                (*elenco)[i].hasThisSurname(surnamePattern) &&
                (*elenco)[i].hasThisBalance(balanceValue, balancePattern)){
            c.push_back(i);
        }
    }
    return c;
}

double ElencoConti::getCommissioneDepositoCC() {
    return ContoCorrente::getCommissioneDeposito();
}

double ElencoConti::getCommissionePrelievoCC() {
    return ContoCorrente::getCommissionePrelievo();
}

int ElencoConti::getNumConti() const {
    return elenco->getSize();
}

double ElencoConti::getSaldoTotale() const {
    double saldoTot = 0;
    for(int i = 0; i < elenco->getSize(); i++){
        saldoTot += ((*elenco)[i])->getSaldo();
    }
    return saldoTot;
}

ElencoConti::ContoPtr& ElencoConti::getAccount(Container<ElencoConti::ContoPtr>::Iterator i){
    return (*elenco)[i];
}

/**
 * @param os è lo stream su cui stampare.
 * @param e è l'elenco che si vuole stampare.
 */
ostream& operator<<(ostream& os, const ElencoConti& e){
    Container<ElencoConti::ContoPtr>& el = *(e.elenco);
    for(Container<ElencoConti::ContoPtr>::ConstIterator it = el.begin(); it != el.end(); it++){
        os << (*it)->toString();
    }
    return os;
}

bool ElencoConti::ContoPtr::hasThisName(string pattern) const {
    if (pattern == "*" || pattern == "")
        return true;
    return punt->getNome() == pattern;
}

bool ElencoConti::ContoPtr::hasThisSurname(string pattern) const {
    if (pattern == "*" || pattern == "")
        return true;
    return punt->getCognome() == pattern;
}

bool ElencoConti::ContoPtr::hasThisBalance(double value, string pattern) const {
    if(pattern == "*" || pattern == "")
        return true;
    double b = punt->getSaldo();
    if(pattern == "=")
        return b == value;
    else if(pattern == ">")
        return b > value;
    else if(pattern == ">=")
        return b >= value;
    else if(pattern == "<")
        return b < value;
    else if(pattern == "<=")
        return b <= value;
    else
        return false;

}

ElencoConti::ContoPtr::ContoPtr(ContoBancario* p): punt(p) {}

ElencoConti::ContoPtr::ContoPtr(const ContoPtr & cp): punt(cp.punt->clona()) {}

ElencoConti::ContoPtr& ElencoConti::ContoPtr::operator =(const ContoPtr& cbp){
    if(this != &cbp){
        delete punt;
        punt = cbp->clona();
    }
    return *this;
}

bool ElencoConti::ContoPtr::operator ==(const ContoPtr& p) const{
    return punt == p.punt;
}

bool ElencoConti::ContoPtr::operator !=(const ContoPtr& p) const{
    return punt != p.punt;
}

ContoBancario& ElencoConti::ContoPtr::operator *(){
    return *punt;
}

const ContoBancario& ElencoConti::ContoPtr::operator *() const {
    return *punt;
}

ContoBancario* ElencoConti::ContoPtr::operator ->(){
    return punt;
}

const ContoBancario* ElencoConti::ContoPtr::operator ->() const {
    return punt;
}

ElencoConti::ContoPtr::~ContoPtr(){
    delete punt;
}


