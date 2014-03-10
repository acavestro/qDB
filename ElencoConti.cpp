#include "ElencoConti.h"
using std::cout;

ElencoConti::ElencoConti(): elenco(new Container<ContoPtr>){}

/**
 * @param cbp è il puntatore al ContoBancario che
 * si vuole aggiungere
 */
void ElencoConti::addAccount(ContoBancario * cbp){
    elenco->addItem(cbp);
}

/**
 * @param cbp è il puntatore al ContoBancario che
 * si vuole aggiungere
 */
void ElencoConti::addAccountIfNotPresent(ContoBancario * cbp){
    ContoPtr p = cbp;
    if(!elenco->contains(p))
        elenco->addItem(p);
}

/**
 * @param cb è il conto da cancellare
 */
void ElencoConti::deleteAccount(ContoBancario * cb){
    elenco->removeItem(cb);
}

/**
 * @param it è l'iteratore dell'elemento da rimuovere
 */
void ElencoConti::deleteAccount(Container<ContoPtr>::Iterator it){
    elenco->removeItem(it);
}

/**
 * @param namePattern è il nome da cercare (o *)
 * @param surnamePattern è il cognome da cercare (o *)
 * @param balancePattern è il pattern del saldo (=, >, >=, <, <=)
 * @param balanceValue è il valore su cui applicare il pattern del saldo
 */
ElencoConti::ContoPtr* ElencoConti::searchSingleAccount(string namePattern,
                                           string surnamePattern,
                                           string balancePattern,
                                           double balanceValue){
    bool found = false;
    Container<ContoPtr>::Iterator itToReturn;
    for(Container<ContoPtr>::Iterator it = elenco->begin();
        !found && it!=elenco->end(); it++) {
        if(accountHasThisName((*elenco)[it], namePattern) &&
                accountHasThisSurname((*elenco)[it], surnamePattern) &&
                accountHasThisBalance((*elenco)[it], balanceValue, balancePattern)){
            found = true;
            itToReturn = it;
        }
    }
    if (found)
        return &((*elenco)[itToReturn]);
    else
        return 0;
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

bool ElencoConti::accountHasThisName(ContoPtr acc, string pattern) const {
    if (pattern == "*" || pattern == "")
        return true;
    return acc->getNome() == pattern;
}

bool ElencoConti::accountHasThisSurname(ContoPtr acc, string pattern) const {
    if (pattern == "*" || pattern == "")
        return true;
    return acc->getCognome() == pattern;
}

bool ElencoConti::accountHasThisBalance(ContoPtr acc, double value, string pattern) const {
    if(pattern == "*" || pattern == "")
        return true;
    double b = acc->getSaldo();
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


