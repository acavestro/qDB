#include "CBPpointer.h"

CBPointer::CBPointer(ContoBancario* p): punt(p) {}

CBPointer& CBPointer::operator =(const CBPointer& cbp){
    if(this != &cbp){
        delete punt;
        punt = cbp->clona();
    }
}

bool CBPointer::operator ==(const CBPointer& p) const{
    return punt == p.punt;
}

bool CBPointer::operator !=(const CBPointer& p) const{
    return punt != p.punt;
}

ContoBancario& CBPointer::operator *(){
    return *punt;
}

const ContoBancario& CBPointer::operator *() const {
    return *punt;
}

ContoBancario* CBPointer::operator ->(){
    return punt;
}

const ContoBancario* CBPointer::operator ->() const {
    return punt;
}

CBPointer::~CBPointer(){
    delete punt;
}


