#ifndef CONTAINER_H
#define CONTAINER_H
/**
 * @brief Classe Container<K>.
 * Modella un contenitore di elementi.
 */
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
    CItemPointer searchItem(const K&) const;
    //static CItemPointer clone(ConstIterator&, ConstIterator);
public:
    /**
     * @brief Classe Iterator.
     * Modella un indice per scorrere gli elementi
     * del Container e permettere side-effect su di
     * essi.
     */
    class Iterator {
        friend class Container;
    private:
        CItemPointer punt;
    public:
        /**
         * @brief Costruttore di default.
         */
        //Permette anche la conversione implicita da
        //CItemPointer, ma questo agli utenti non interessa
        //perché questa classe non fa parte dell'interfaccia pubblica
        Iterator(CItemPointer = 0);
        //SI DOVREBBE PENSARE A UN MODO PER AGGIUNGERE K& operator*();
        //Idea: avrebbe senso un Iterator(ConstIterator)? Non credo.
        /**
         * @brief Operatore di uguaglianza
         * @return Un valore booleano pari a true se i
         * due Iterator puntano allo stesso elemento,
         * altrimenti false.
         */
        bool operator==(const Iterator&) const;
        /**
         * @brief Operatore di disuguaglianza.
         * @return Un valore booleano pari a true se i
         * due Iterator NON puntano allo stesso momento,
         * altrimenti false.
         */
        bool operator!=(const Iterator&) const;
        /**
         * @brief Operatore d'incremento prefisso.
         * @return Un oggetto di tipo Iterator rappresentante
         * lo stato dell'oggetto d'instanza dopo l'operazione
         * d'incremento.
         */
        Iterator& operator++();
        /**
         * @brief Operatore d'incremento postfisso.
         * @return Un oggetto di tipo Iterator rappresentante
         * lo stato dell'oggetto d'instanza prima dell'operazione
         * d'incremento.
         */
        Iterator operator++(int);
    };

    /**
     * @brief Classe ConstIterator.
     * Modella un indice per scorrere gli elementi
     * del Container SENZA permettere side-effect ssu
     * di essi, permettendo quindi solo un accesso
     * in sola lettura.
     */
    class ConstIterator {
        friend class Container;
    private:
        CItemPointer punt;
    public:
        /**
         * @brief Costruttore di default.
         */
        //Permette anche la conversione implicita da
        //CItemPointer, ma questo agli utenti non interessa
        //perché questa classe non fa parte dell'interfaccia pubblica
        ConstIterator(CItemPointer = 0);
        /**
         * @brief Costruttore che crea un interatore costante
         * a partire da uno non costante.
         */
        ConstIterator(const Iterator&);
        /**
         * @brief Operatore di dereferenziazione.
         * @return Un riferimento costante all'elemento
         * puntato dal ConstIterator.
         */
        const K& operator*() const;
        /**
         * @brief Operatore di accesso a membro.
         * @return Un puntatore all'elemento
         * puntato dal ConstIterator, marcato costate.
         */
        const K* operator->() const;
        /**
         * @brief Operatore di uguaglianza
         * @return Un valore booleano pari a true se i
         * due ConstIterator puntano allo stesso elemento,
         * altrimenti false.
         */
        bool operator==(const ConstIterator&) const;
        /**
         * @brief Operatore di disuguaglianza.
         * @return Un valore booleano pari a true se i
         * due CnostIterator NON puntano allo stesso momento,
         * altrimenti false.
         */
        bool operator!=(const ConstIterator&) const;
        /**
         * @brief Operatore d'incremento prefisso.
         * @return Un oggetto di tipo ConstIterator rappresentante
         * lo stato dell'oggetto d'instanza dopo l'operazione
         * d'incremento.
         */
        ConstIterator& operator++();
        /**
         * @brief Operatore d'incremento postfisso.
         * @return Un oggetto di tipo ConstIterator rappresentante
         * lo stato dell'oggetto d'instanza prima dell'operazione
         * d'incremento.
         */
        ConstIterator operator++(int);
    };

    /**
     * @brief Costruttore di default. Inizializza il container
     * con zero elementi.
     */
    Container();
    /**
     * @brief Costruttore di copia.
     */
    Container(const Container&);
    // PROPOSTE DI AGGIUNTA
    //Container(const Container&, ConstIterator, ConstIterator);
    //~Container();
    /**
     * @brief Test sulla presenza di elementi nel Container.
     * @return Un valore booleano pari a true se il Container
     * è vuoto, cioè non contiene elementi, altrimenti false.
     */
    bool isEmpty() const;
    /**
     * @brief Aggiunge un elemento al contenitore.
     */
    void addItem(const K&);
    /**
     * @brief Rimuove un elemento dal contenitore.
     */
    void removeItem(const K&);
    /**
     * @brief Rimuove dal contenitore l'elemento
     * puntato dall'Iterator passato come parametro.
     */
    void removeItem(Iterator);
    /**
     * @brief Test sulla dimensione del Container.
     * @return Un valore intero contenente il numero di
     * elementi presenti nel contenitore.
     */
    int getSize() const;
    /**
     * @brief Cerca un elemento K nel contenitore
     * e se presente ne restituisce un iteratore.
     * In caso di multiple presenze, restituisce un
     * iteratore alla prima occorrenza.
     * @return Un oggetto di tipo Iterator contenente
     * la posizione dell'elemento, nel caso ci sia,
     * altrimenti un valore pari a end().
     */
    Iterator indexOf(K&);
    /**
     * @brief Cerca un elemento K nel contenitore
     * e se presente ne restituisce un iteratore costante.
     * In caso di multiple presenze, restituisce un
     * iteratore costante alla prima occorrenza.
     * @return Un oggetto di tipo ConstIterator contenente
     * la posizione dell'elemento, nel caso ci sia,
     * altrimenti un valore pari a end().
     */
    ConstIterator indexOf(const K&) const;
    /**
     * @brief Test sulla presenza di un elemento
     * nel contenitore.
     * @return Un valore booleano pari a true se è
     * presente, altrimenti false.
     */
    bool contains(const K&) const;
    /**
     * @brief Primo elemento del contenitore.
     * @return Un oggetto di tipo Iterator che punta
     * al primo elemento del Container.
     */
    Iterator begin();
    /**
     * @brief Primo elemento del contenitore.
     * @return Un oggetto di tipo ConstIterator che punta
     * al primo elemento del Container.
     */
    ConstIterator begin() const;
    /**
     * @brief Elemento successivo all'ultimo.
     * @return Un oggetto di tipo Iterator che punta
     * all'elemento successivo all'ultimo.
     */
    Iterator end();
    /**
     * @brief Elemento successivo all'ultimo.
     * @return Un oggetto di tipo ConstIterator che punta
     * all'elemento successivo all'ultimo.
     */
    ConstIterator end() const;
    /**
     * @brief Operatore di subscripting
     * @return Un riferimento ad un elemento del container.
     */
    K& operator[](Iterator&);
    /**
     * @brief Operatore di subscripting
     * @return Un riferimento COSTANTE ad un elemento del container.
     */
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

/*
// operatore di dereferenziazione che restituisce un K&
// ATTENZIONE: da usare solo se effettivamente s'intende fare side-effect
// sugli elementi del Container, in quanto questo metodo esegue delle copie
// al fine di preservare l'integrità della memoria condivisa (da più Container)
// che potrebbero essere inutili nel caso si acceda per eseguire solo letture.
template <class K>
K& Container<K>::Iterator::operator*() {
    // l'uso di un Iterator prevede che si facciano side-effect
    // sugli elementi contenuti. Copio la lista per preservare l'integrità
    // della memoria condivisa.



}
*/

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

// definizione operatore di dereferenziazione
template <class K>
const K& Container<K>::ConstIterator::operator *() const {
    return punt->info;
}

// definizione operatore di accesso a membro
template <class K>
const K* Container<K>::ConstIterator::operator ->() const {
    return &(punt->info);
}

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
/**
 * @param item è l'elemento da aggiungere.
 */
template <class K>
void Container<K>::addItem(const K& item){
    first = new CItem(item, first);
    size++;
}

// rimuove un elemento const K& item dal contenitore
// ricercandolo nella lista.
/**
 * Se ci sono più occorrenze di item viene
 * eliminata solo la prima.
 * @param item è l'elemento da (eventualmente) eliminare.
 */
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

/**
 * La rimozione provoca la copia della lista dall'inizio
 * fino all'elemento precedente a quello che si vuole
 * cancellare.
 * @param it è l'Iterator che punta all'elemento
 * da rimuovere.
 */
template <class K>
void Container<K>::removeItem(Iterator it){
    removeItem(it.punt->info);
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
/**
 * ATTENZIONE: da usare solo se effettivamente s'intende fare side-effect
 * sugli elementi del Container, in quanto questo metodo esegue delle copie
 * al fine di preservare l'integrità della memoria condivisa (da più Container)
 * che potrebbero essere inutili nel caso si acceda per eseguire solo letture.
 */
template <class K>
K& Container<K>::operator[](Iterator& it) {
    // l'uso di un Iterator prevede che si facciano side-effect
    // sugli elementi contenuti. Copio la lista per preservare l'integrità
    // della memoria condivisa.

    CItemPointer p = first, prec, q;
    //CItemPointer original = first;
    bool trovato = false;
    while(p != 0 && !trovato){
        q = new CItem(p->info, p->next);
        if (prec == 0){
            first = q;
            prec = q;
        } else {
            prec->next = q;
            prec = prec->next;
        }

        if(p == it.punt)
            trovato = true;
        p = p->next;
    }
    it.punt = prec;
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

// cerca un elemento K nella lista e restituisce un CItemPointer ad esso
template <class K>
typename Container<K>::CItemPointer Container<K>::searchItem(const K& item) const {
    bool found = false;
    CItemPointer p = 0;
    for(ConstIterator it = begin(); !found && it != end(); it++){
        found = (*it == item);
        p = it.punt;
    }
    if(found)
        return p;
    else
        return 0;
}

// restituisce un Iterator all'elemento del parametro attuale
// se non presente l'Iterator è uguale a Container<K>::end()
/**
 * @param item è l'elemento di cui si vuole ottenere l'indice.
 */
template <class K>
typename Container<K>::Iterator Container<K>::indexOf(K& item) {
    return searchItem(item);
}

// restituisce un ConstIterator all'elemento del parametro attuale
// se non presente l'Iterator è uguale a Container<K>::end()
/**
 * @param item è l'elemento di cui si vuole ottenere l'indice.
 */
template <class K>
typename Container<K>::ConstIterator Container<K>::indexOf(const K & item) const {
    return searchItem(item);
}

// restituisce true se l'elemento è presente, altrimenti false
/**
 * @param item è l'elemento di cui si vuole verificare la presenza.
 */
template <class K>
bool Container<K>::contains(const K& item) const {
    return indexOf(item) != end();
}

/*
// copia il container delimitato dai due ConstIterator
// (itBegin compreso, itEnd non compreso)
// e restituisce il puntatore al primo elemento
// per valore e il puntatore all'ultimo tramite
// side-effect su itBegin;
template <class K>
static Container<K>::CItemPointer Container<K>::clone(ConstIterator& itBegin, ConstIterator itEnd) const {
    CItemPointer first = new CItem(*itBegin);
    CItemPointer p = first;
    while(++itBegin != itEnd){
        p->next = new CItem(*it);
        p = p->next;
    }
    return first;
}
*/
#endif // CONTAINER_H
