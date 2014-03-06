#ifndef CONTAINER_H
#define CONTAINER_H

template <class K>
class Container {
    friend class Iterator;
    friend class ConstIterator;
private:
    class CItemPointer;
    class CItem {
    public:
        K info;
        CItemPointer next;
        int referrarls;

        CItem();
        CItem(const K&);
        CItem(const K&, const CItemPointer&);
    };
    class CItemPointer {
    public:
        CItem* itemPointer;

        CItemPointer(CItem* = 0);
        CItemPointer(const CItemPointer&);
        ~CItemPointer();
        CItemPointer& operator=(const CItemPointer&);
        CItem& operator*() const;
        CItem* operator->() const;
        bool operator==(const CItemPointer&) const;
        bool operator!=(const CItemPointer&) const;
    };
    CItemPointer first;
    int size;
public:
    class Iterator {
        friend class Container;
    private:
        CItemPointer punt;
    public:
        Iterator(CItemPointer = 0);
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;
        Iterator& operator++();
        Iterator operator++(int);
    };

    class ConstIterator {
        friend class Container;
    private:
        CItemPointer punt;
    public:
        ConstIterator(CItemPointer = 0);
        ConstIterator(const Iterator&);
        bool operator==(const ConstIterator&) const;
        bool operator!=(const ConstIterator&) const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
    };

    Container();
    Container(const Container&);
    //Container(const Container&, ConstIterator, ConstIterator);
    //~Container();
    bool isEmpty() const;
    void addItem(const K&);
    void removeItem(const K&);
    int getSize() const;

    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    K& operator[](Iterator);
    const K& operator[](ConstIterator) const;
};

// Definizioni dei metodi della classe Container<K>::CItem

// costruttore di default
template <class K>
Container<K>::CItem::CItem(): next(0), referrarls(0) {}

// costruttore che accetta come parametro formale
// un const reference di un K.
template <class K>
Container<K>::CItem::CItem(const K& item): info(item) {}

// costruttore che accetta come parametro formale
// un const reference di un K e un CItemPointer al CItem successivo.
template <class K>
Container<K>::CItem::CItem(const K& item, const CItemPointer& p_next): info(item), next(p_next) {}

// ---

// Definizioni dei metodi della classe Container<K>::CItemPointer

// costruttore di default che accetta come parametro formale un CItem*
// di default = 0. Quindi questo costruttore fornisce anche la conversione
// CItem* ==> CItemPointer
template <class K>
Container<K>::CItemPointer::CItemPointer(CItem* p): itemPointer(p) {
    if (itemPointer)
        itemPointer->referrarls++;
}

// costruttore di copia
template <class K>
Container<K>::CItemPointer::CItemPointer(const CItemPointer& p): itemPointer(p.itemPointer){
    if (itemPointer)
        itemPointer->referrarls++;
}

// distruttore
template <class K>
Container<K>::CItemPointer::~CItemPointer(){
    if (itemPointer){
        itemPointer->referrarls--;
        if(itemPointer->referrarls == 0)
            delete itemPointer;
    }
}

// definizione operatore di assegnazione
template <class K>
typename Container<K>::CItemPointer& Container<K>::CItemPointer::operator=(const CItemPointer& p){
    if (this != &p){
        CItem* temp = itemPointer;
        itemPointer = p.itemPointer;
        if (itemPointer)
            itemPointer->referrarls++;
        if (temp){
            temp->referrarls--;
            if (temp->referrarls == 0)
                delete temp;
        }
    }
    return *this;
}

// definizione operatore di dereferenziazione
template <class K>
typename Container<K>::CItem& Container<K>::CItemPointer::operator*() const {
    return *itemPointer;
}

// definzione operatore di accesso a membro
template <class K>
typename Container<K>::CItem* Container<K>::CItemPointer::operator->() const {
    return itemPointer;
}

// definizione operatore di uguaglianza
template <class K>
bool Container<K>::CItemPointer::operator==(const CItemPointer& p) const {
    return itemPointer == p.itemPointer;
}

// definzione operatore di disuguaglianza
template <class K>
bool Container<K>::CItemPointer::operator!=(const CItemPointer& p) const {
    return itemPointer != p.itemPointer;
}

// ---

// Definizione metodi della classe Container<K>::Iterator

// Costruttore di default che accetta un parametro formale CItemPointer,
// di default = 0. Quindi effettua anche una conversione implicita
// CItemPointer => Iterator
template <class K>
Container<K>::Iterator::Iterator(CItemPointer p): punt(p) {}

// definizione operatore di uguaglianza
template <class K>
bool Container<K>::Iterator::operator==(const Iterator& i) const {
    return punt == i.punt;
}

// definizione operatore di disuguaglianza
template <class K>
bool Container<K>::Iterator::operator!=(const Iterator& i) const {
    return punt != i.punt;
}

// definizione operatore di incremento prefisso
template <class K>
typename Container<K>::Iterator& Container<K>::Iterator::operator++() {
    if (punt)
        punt = punt.itemPointer->next;
    return *this;
}

// definizione operatore di incremento postfisso
template <class K>
typename Container<K>::Iterator Container<K>::Iterator::operator++(int){
    Iterator aux = *this;
    if (punt != 0)
        punt = punt.itemPointer->next;
    return aux;
}


// ---

// Definizione metodi della classe Container<K>::ConstIterator

// Costruttore di default che accetta un parametro formale CItemPointer,
// di default = 0. Quindi effettua anche una conversione implicita
// CItemPointer => ConstIterator
template <class K>
Container<K>::ConstIterator::ConstIterator(CItemPointer p): punt(p) {}

// costruttore che accetta come parametro formale un Iterator
// abilita una conversione implicita Iterator => ConstIterator
template <class K>
Container<K>::ConstIterator::ConstIterator(const Iterator & it): punt(it.punt) {}
// definizione operatore di uguaglianza
template <class K>
bool Container<K>::ConstIterator::operator==(const ConstIterator& i) const {
    return punt == i.punt;
}

// definizione operatore di disuguaglianza
template <class K>
bool Container<K>::ConstIterator::operator!=(const ConstIterator& i) const {
    return punt != i.punt;
}

// definizione operatore di incremento prefisso
template <class K>
typename Container<K>::ConstIterator& Container<K>::ConstIterator::operator++() {
    if (punt)
        punt = punt.itemPointer->next;
    return *this;
}

// definizione operatore di incremento postfisso
template <class K>
typename Container<K>::ConstIterator Container<K>::ConstIterator::operator++(int){
    ConstIterator aux = *this;
    if (punt != 0)
        punt = punt.itemPointer->next;
    return aux;
}

// ---

// Definizione metodi della classe Container<K>

// costruttore di default
template <class K>
Container<K>::Container(): first(0), size(0) {}

// costruttore di copia
template <class K>
Container<K>::Container(const Container & c): first(c.first), size(c.size) {}
// il costruttore di copia non fa altro che costruire il campo dati
// first copiandolo da c.first. La memoria resta condivisa.
// Verrà effettivamente eseguita una copia della lista quando ce ne
// sarà effettivamente bisogno (rimozione, accesso ad un CItem tramite
// un Iterator, ecc..)


/*
// costruttore di copia che inizializza il Container con una porzione
// del container c, delimitata dai due iteratori.
template <class K>
Container<K>::Container(const Container & c, ConstIterator itBegin, ConstIterator itEnd):
    first(new CItem(c[itBegin])), size(1) {

    CItemPointer p = first;
    ConstIterator q = itBegin++;

    while(q != itEnd){
        p->next = new CItem(c[q]);
        p = p->next;
        q++;
        size++;
    }
    p->next = 0;
}
*/

//~Container();

// restituisce true se il contenitore è vuoto
template <class K>
bool Container<K>::isEmpty() const {
    return size == 0;
}

// aggiunge un elemento IN TESTA alla lista del contenitore
template <class K>
void Container<K>::addItem(const K& item){
    first = new CItem(item, first);
    size++;
}

// rimuove un elemento const K& item dal contenitore
// ricercandolo nella lista. Se ci sono più occorrenze
// di item viene eliminata solo la prima trovata
template <class K>
void Container<K>::removeItem(const K& item){
    if (!isEmpty()){
        CItemPointer p = first, prec, q;
        CItemPointer original = first;
        first = 0;
        // p scorre la lista, prec è il nodo che precede
        // quello puntato da p, q punta alla copia del nodo
        while(p != 0 && !(p->info == item)){
            q = new CItem(p->info, p->next);
            if (prec == 0)
                first = q;
            else
                prec->next = q;

            prec = q;
            p = p->next;
        }

        if (p == 0){
            first = original;
        } else if (prec == 0) {
            first = p->next;
            size--;
        } else {
            prec->next = p->next;
            size --;
        }
    }
}

// restituisce un Iterator al primo elemento della lista
template <class K>
typename Container<K>::Iterator Container<K>::begin() {
    return Iterator(first);
}

// restituisce un ConstIterator al primo elemento della lista
template <class K>
typename Container<K>::ConstIterator Container<K>::begin()  const {
    return ConstIterator(first);
}

// restituisce un Iterator all'elemento past-the-end del
// container
template <class K>
typename Container<K>::Iterator Container<K>::end() {
    return Iterator(0);
}

// restituisce un ConstIterator all'elemento past-the-end del
// container
template <class K>
typename Container<K>::ConstIterator Container<K>::end() const {
    return ConstIterator(0);
}

// operatore di subscripting con un parametro formale di tipo Iterator
// e che restituisce un K&
// ATTENZIONE: da usare solo se effettivamente s'intende fare side-effect
// sugli elementi del Container, in quanto questo metodo esegue delle copie
// al fine di preservare l'integrità della memoria condivisa (da più Container)
// che potrebbero essere inutili nel caso si acceda per eseguire solo letture.
template <class K>
K& Container<K>::operator[](Iterator it) {
    // l'uso di un Iterator prevede che si facciano side-effect
    // sugli elementi contenuti. Copio la lista per preservare l'integrità
    // della memoria condivisa.

    CItemPointer p = first, prec, q;
    CItemPointer original = first;
    bool trovato = false;
    while(p != 0 && !trovato){
        q = new CItem(p->info, p->next);
        if (prec == 0)
            first = q;
        else
            prec->next = q;

        prec = q;

        if(p == it.punt)
            trovato = true;
        p = p->next;
    }
    prec->next = it.punt->next;
    return prec->info;
}

// operatore di subscripting con un parametro formale di tipo ConstIterator
// e che restituisce un const K&
template <class K>
const K& Container<K>::operator[](ConstIterator cit) const {
    return (cit.punt)->info;
}

// restituisce il numero di elementi del Container
template <class K>
int Container<K>::getSize() const {
    return size;
}

#endif // CONTAINER_H
