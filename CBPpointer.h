#ifndef CBPPOINTER_H
#define CBPPOINTER_H
#include <ContoBancario.h>

class CBPointer
{
public:
    CBPointer(ContoBancario* =0);
    //CBPointer(const CBPointer&);
    ~CBPointer();
    CBPointer& operator=(const CBPointer&);
    bool operator==(const CBPointer&) const;
    bool operator!=(const CBPointer&) const;
    ContoBancario& operator*();
    const ContoBancario& operator*() const;
    ContoBancario* operator->();
    const ContoBancario* operator->() const;
private:
    ContoBancario* punt;
};

#endif // CBPPOINTER_H
