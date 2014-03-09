#include "ElencoConti.h"
using std::cout;

ElencoConti::ElencoConti(): elenco(new Container<ContoPtr>){}

void ElencoConti::aggiungiConto(ContoBancario * cbp){
    elenco->addItem(cbp);
}

void ElencoConti::aggiungiContoSeNonPresente(ContoBancario * cbp){
    ContoPtr p = cbp;
    if(!elenco->contains(p))
        elenco->addItem(p);
}


ostream& operator<<(ostream& os, const ElencoConti& e){
    Container<ElencoConti::ContoPtr>& el = *(e.elenco);
    for(Container<ElencoConti::ContoPtr>::ConstIterator it = el.begin(); it != el.end(); it++){
        os << (*it)->toString();
    }
    return os;
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


