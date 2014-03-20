#ifndef CONTAINER_H
#define CONTAINER_H

#define LOAD_TO_EXPAND 1
#define EXPANSION_FACTOR 2
#define LOAD_TO_SHRINK 0.25
#define SHRINK_FACTOR 0.5

/*********** DICHIARAZIONI ***********/
/**
 * Classe Container<K>. Gestisce una collezione
 * di elementi di tipo K organizzati un array
 * di dimensione dinamicamente variabile. La
 * memoria è gestita senza condivisione.
 */
template <class K>
class Container {
private:
    class CItem {
    public:
       K info;

       CItem();
       CItem(const K&);
    };

    CItem** vector;
    int size;
    int capacity;

    double load() const;
    void expand();
    void shrink();
    CItem** clone() const;
    void destroy();
    void moveForward(int);
    void moveBackward(int);
    int position(const K&) const;
public:
    /**
     * Costruttore di default. Allora un array di DIM celle,
     * con DIM = 10 di default.
     */
    Container(int =10);
    /**
     * Costruttore di copia. Effettua la copia profonda
     * dell'array del contenitore passato come riferimento
     * costante.
     */
    Container(const Container&);
    /**
     * Operatore di assegnazione.
     * @return Il contenitore assegnato, effettuando la
     * copia profonda.
     */
    Container& operator=(const Container&);
    /**
     * Distruttore. Si occupa di distruggere la memoria
     * allocata dal Contenitore.
    */
    ~Container();
    /**
     * Inserimento in coda.
     */
    void push_back(const K&);
    /**
     * Test di contenitore vuoto.
     * @return Un valore booleano pari a true se il
     * contenitore è vuoto, ossia non contiene elementi,
     * altrimenti false.
     */
    bool isEmpty() const;
    /**
     * Numero di oggetti contenuti.
     * @return Un valore intero pari al numero di oggetti
     * presenti nel contenitore.
     */
    int getSize() const;
    /**
     * Capacità del contenitore.
     * @return Un valore intero pari al numero di celle
     * allocate nel contenitore, comprese quelle vuote.
     */
    int getCapacity() const;
    /**
     * Cancellazione in coda.
     * @return Un riferimento al valore estratto in coda
     * dal contenitore.
     */
    K& pop_back();


    class Iterator;
    /**
     * Classe ConstIterator. Rappresenta un indice costante a un
     * elemento del contenitore. Può essere usato in due modi:
     * come un intero, sfruttando la conversione implicita del
     * costruttore di default, oppure come un indice smart costruendolo
     * tramite la funzione begin() del Container abilitando in questo
     * caso anche gli operatori di dereferenziazione e accesso a membro.
     */
    class ConstIterator {
        friend class Container;
    private:
        int index;
        CItem** base;
        ConstIterator(int, CItem**);
    public:
        /**
         * Costruttore di default. Accetta un valore di tipo int,
         * abilitando la conversione int => ConstIterator.
         */
        ConstIterator(int = 0);
        /**
         * Costruttore di conversione da Iterator.
         */
        ConstIterator(const Iterator&);
        /**
         * Operatore di uguaglianza.
         */
        bool operator==(const ConstIterator&) const;
        /**
         * Operatore di disuguaglianza.
         */
        bool operator!=(const ConstIterator&) const;
        /**
         * Operatore di dereferenziazione. Non permette side-effect
         * sull'oggetto puntato. Usare SOLO se il ConstIterator è
         * stato istanziato tramite la funzione begin().
         */
        const K& operator*() const;
        /**
         * Operatore di accesso a membro. Non permette side-effect
         * sull'oggetto puntato. Usare SOLO se il ConstIterator è
         * stato istanziato tramite la funzione begin().
         */
        const K* operator->() const;
        /**
         * Operatore d'incremento prefisso.
         */
        ConstIterator& operator++();
        /**
         * Operatore d'incremento postfisso.
         */
        ConstIterator operator++(int);
        /**
         * Operatore di decremento prefisso.
         */
        ConstIterator& operator--();
        /**
         * Operatore di decremento postfisso.
         */
        ConstIterator operator--(int);
    };

    /**
     * Classe Iteratore. Rappresenta un indice ad un elemento
     * del contenitore. Può essere usato in due modi:
     * come un intero, sfruttando la conversione implicita del
     * costruttore di default, oppure come un indice smart costruendolo
     * tramite la funzione begin() del Container abilitando in questo
     * caso anche gli operatori di dereferenziazione e accesso a membro.
     */
    class Iterator {
        friend class Container;
    private:
        int index;
        CItem** base;
        Iterator(int, CItem**);
    public:
        /**
         * Costruttore di default. Accetta un valore di tipo int,
         * abilitando la conversione int => Iterator.
         */
        Iterator(int =0);
        /**
         * Operatore di uguaglianza.
         */
        bool operator==(const Iterator&) const;
        /**
         * Operatore di disuguaglianza.
         */
        bool operator!=(const Iterator&) const;
        /**
         * Operatore di dereferenziazione. Permette side-effect
         * sull'oggetto puntato. Usare SOLO se l'Iterator è
         * stato istanziato tramite la funzione begin().
         */
        K& operator*();
        /**
         * Operatore di accesso a membro. Permette side-effect
         * sull'oggetto puntato. Usare SOLO se l'Iterator è
         * stato istanziato tramite la funzione begin().
         */
        K* operator->();
        /**
         * Operatore d'incremento prefisso.
         */
        Iterator& operator++();
        /**
         * Operatore d'incremento postfisso.
         */
        Iterator operator++(int);
        /**
         * Operatore di decremento prefisso.
         */
        Iterator& operator--();
        /**
         * Operatore di decremento postfisso.
         */
        Iterator operator--(int);
    };

    /**
     * Iteratore iniziale.
     * @return Un Iterator al primo elemento del contenitore.
     */
    Iterator begin();
    /**
     * Iteratore iniziale costante.
     * @return Un ConstIterator al primo elemento del contenitore.
     */
    ConstIterator begin() const;
    /**
     * Iteratore past-the-end.
     * @return Un Iterator che punta all'elemento successivo
     * all'ultimo.
     */
    Iterator end();
    /**
     * Iteratore past-the-end costante.
     * @return Un ConstIterator che punta all'elemento successivo
     * all'ultimo
     */
    ConstIterator end() const;
    /**
     * Operatore di subscrpting costante.
     * @return Un riferimento costante all'oggetto puntato
     * dal ConstIterator.
     */
    const K& operator[](ConstIterator) const;
    /**
     * Operatore di subscripting.
     * @return Un riferimento all'oggetto puntato dall'Iterator.
     */
    K& operator[](Iterator);
    /**
     * Rimozione semplice. Cerca l'elemento passato come riferimento
     * costante e, se presente, ne rimuove la prima occorrenza dal
     * Contenitore.
     */
    void removeElement(const K&);
    /**
     * Rimozione ad accesso casuale. Cancella dal Contenitore
     * l'elemento puntato dall'Iterator.
     */
    void removeElementAt(Iterator);
    /**
     * Inserimento ad accesso casuale. Inserisce l'elemento passato
     * come riferimento costante nella posizione puntata da Iterator.
     */
    void insertElementAt(const K&, Iterator);
    /**
     * Indice dell'elemento.
     * @return Un Iterator rappresentante la posizione della prima occorrenza
     * dell'elemento all'interno del contenitore, se c'è. Altrimenti ritorna
     * un Iterator rappresentante il valore -1.
     */
    Iterator indexOf(const K&);
    /**
     * Indice costante dell'elemento.
     * @return Un ConstIterator rappresentante la posizione della prima occorrenza
     * dell'elemento all'interno del contenitore, se c'è. Altrimenti ritorna
     * un ConstIterator rappresentante il valore -1.
     */
    ConstIterator indexOf(const K&) const;
    /**
     * Test di presenza.
     * @return Un valore booleano pari a true se è presente almeno un'occorrenza
     * dell'elemento passato come riferimento cstante. Altrimenti, false.
     */
    bool contains(const K&) const;
};

/*********** DEFINIZIONI **********/

// Definizioni dei metodi della classe Container<K>::CItem

// costruttore di default
template <class K>
Container<K>::CItem::CItem() {}

// costruttore che accetta come parametro formale
// un const reference di un K.
template <class K>
Container<K>::CItem::CItem(const K& item): info(item){}

// Definizione metodi della classe Container<K>::ConstIterator

// Costruttore di default che accetta un parametro formale intero,
// di default = 0. Quindi effettua anche una conversione implicita
// int => ConstIterator
template <class K>
Container<K>::ConstIterator::ConstIterator(int i): index(i), base(0) {}

// costruttore che accetta come parametro formale un Iterator
// abilita una conversione implicita Iterator => ConstIterator
template <class K>
Container<K>::ConstIterator::ConstIterator(const Iterator & it): index(it.index), base(it.base) {}

template <class K>
Container<K>::ConstIterator::ConstIterator(int i, CItem** p): index(i), base(p){}

// definizione operatore di uguaglianza
template <class K>
bool Container<K>::ConstIterator::operator==(const ConstIterator& i) const {
    return index == i.index;
}

// definizione operatore di disuguaglianza
template <class K>
bool Container<K>::ConstIterator::operator!=(const ConstIterator& i) const {
    return index != i.index;
}

// definizione operatore di incremento prefisso
template <class K>
typename Container<K>::ConstIterator& Container<K>::ConstIterator::operator++() {
    index++;
    return *this;
}

// definizione operatore di incremento postfisso
template <class K>
typename Container<K>::ConstIterator Container<K>::ConstIterator::operator++(int){
    ConstIterator aux = *this;
    index++;
    return aux;
}

// definizione operatore di decremento prefisso
template <class K>
typename Container<K>::ConstIterator& Container<K>::ConstIterator::operator--() {
    index--;
    return *this;
}

// definizione operatore di decremento postfisso
template <class K>
typename Container<K>::ConstIterator Container<K>::ConstIterator::operator--(int){
    ConstIterator aux = *this;
    index--;
    return aux;
}

template <class K>
const K& Container<K>::ConstIterator::operator *() const {
    return base[index]->info;
}

template <class K>
const K* Container<K>::ConstIterator::operator ->() const {
    return &(base[index]->info);
}

// Definizione metodi della classe Container<K>::Iterator

// Costruttore di default che accetta un parametro formale intero,
// di default = 0. Quindi effettua anche una conversione implicita
// int => ConstIterator
template <class K>
Container<K>::Iterator::Iterator(int i): index(i) {}

// costruttore che accetta come parametro formale un Iterator
// abilita una conversione implicita Iterator => ConstIterator
//template <class K>
//Container<K>::ConstIterator::ConstIterator(const Iterator & it): index(it.index) {}

template <class K>
Container<K>::Iterator::Iterator(int i, CItem** p): index(i), base(p){}

// definizione operatore di uguaglianza
template <class K>
bool Container<K>::Iterator::operator==(const Iterator& i) const {
    return index == i.index;
}

// definizione operatore di disuguaglianza
template <class K>
bool Container<K>::Iterator::operator!=(const Iterator& i) const {
    return index != i.index;
}

// definizione operatore di incremento prefisso
template <class K>
typename Container<K>::Iterator& Container<K>::Iterator::operator++() {
    index++;
    return *this;
}

// definizione operatore di incremento postfisso
template <class K>
typename Container<K>::Iterator Container<K>::Iterator::operator++(int){
    Iterator aux = *this;
    index++;
    return aux;
}

// definizione operatore di decremento prefisso
template <class K>
typename Container<K>::Iterator& Container<K>::Iterator::operator--() {
    index--;
    return *this;
}

// definizione operatore di decremento postfisso
template <class K>
typename Container<K>::Iterator Container<K>::Iterator::operator--(int){
    Iterator aux = *this;
    index--;
    return aux;
}

template <class K>
K& Container<K>::Iterator::operator *() {
    return base[index]->info;
}

template <class K>
K* Container<K>::Iterator::operator ->() {
    return &(base[index]->info);
}

// ---

// Definizioni dei metodidella classe Container<K>

// costruttore di default
template <class K>
Container<K>::Container(int DIM): vector(new CItem*[DIM]),
                                            size(0),
                                            capacity(DIM) {}

// costruttore di copia
template <class K>
Container<K>::Container(const Container& c): vector(c.clone()),
                                            size(c.size),
                                            capacity(c.capacity){}

template <class K>
Container<K>& Container<K>::operator =(const Container& c){
    if(this != &c){
        destroy();
        vector = c.clone();
        size = c.size;
        capacity = c.capacity;
    }
    return *this;
}

// distruttore
template <class K>
Container<K>::~Container() {
    destroy();
}

// funzione che determina il fattore di carico dell'array
// in modo da determinare quando espanderlo e quando contrarlo;
template <class K>
double Container<K>::load() const{
    return (double) size / capacity;
}

// funzione che espande l'array in caso sia pieno
template <class K>
void Container<K>::expand(){
    int newCapacity = capacity*EXPANSION_FACTOR;
    CItem** v2 = new CItem*[newCapacity];
    for(int i = 0; i < size; i++){
        v2[i] = vector[i];
    }
    delete[] vector;
    vector = v2;
    capacity = newCapacity;
}

// funzione che contra l'array quando è troppo grande
// rispetto al numero di elementi effettivamente contenuti
template <class K>
void Container<K>::shrink(){
    int newCapacity = capacity*SHRINK_FACTOR;
    CItem** v2 = new CItem*[newCapacity];
    for(int i = 0; i < size; i++){
        v2[i] = vector[i];
    }
    delete[] vector;
    vector = v2;
    capacity = newCapacity;
}

// effettua una copia profonda del contenitore.
template <class K>
typename Container<K>::CItem** Container<K>::clone() const {
    CItem** vc = new CItem*[size];
    for(int i = 0; i < size; i++){
        vc[i] = new CItem(vector[i]->info);
    }
    return vc;
}

// effettua una distruzione profonda del contenitore.
template <class K>
void Container<K>::destroy() {
    for(int i = 0; i < size; i++){
        delete vector[i];
    }
    delete[] vector;
}

// sposta in avanti gli elementi dell'array
// pos è l'indice del primo elemento da spostare in avanti
template <class K>
void Container<K>::moveForward(int pos){
    size++;
    if(load() == LOAD_TO_EXPAND)
        expand();

    for(int i = size-1; i > pos; i--){
        vector[i] = vector[i-1];
    }
}

// sposta all'indietro gli elementi dell'array
// pos è la posizione libera dove iniziare a
// spostare gli elementi successivi
template <class K>
void Container<K>::moveBackward(int pos){
    for(int i = pos; i < size; i++){
        vector[i] = vector[i+1];
    }
    size--;
    if(load() == LOAD_TO_SHRINK)
        shrink();
}

// aggiunge un elemento in coda
template <class K>
void Container<K>::push_back(const K & item){
    if(load() == LOAD_TO_EXPAND)
        expand();
    vector[size] = new CItem(item);
    size++;
}

// ritorna il numero di elementi contenuti
template <class K>
int Container<K>::getSize() const {
    return size;
}

// ritorna la capacità
template <class K>
int Container<K>::getCapacity() const {
    return capacity;
}

template <class K>
K& Container<K>::pop_back() {
    CItem* p = vector[size-1];
    size--;
    if(load() == LOAD_TO_SHRINK)
        shrink();
    return p->info;
}

template <class K>
typename Container<K>::Iterator Container<K>::begin(){
    return Iterator(0, vector);
}

template <class K>
typename Container<K>::ConstIterator Container<K>::begin() const {
    return ConstIterator(0, vector);
}

template <class K>
typename Container<K>::Iterator Container<K>::end(){
    return size+1;
}

template <class K>
typename Container<K>::ConstIterator Container<K>::end() const {
    return size+1;
}


// operatore di subscripting per iteratori costanti
template <class K>
const K& Container<K>::operator [](ConstIterator cit) const {
    return vector[cit.index]->info;
}

// operatore di subscrpting per iteratori non costanti.
// permette side-effect
template <class K>
K& Container<K>::operator [](Iterator it){
    vector[it.index] = new CItem(vector[it.index]->info);
    return vector[it.index]->info;
}

template <class K>
void Container<K>::removeElement(const K& item){
    int pos = position(item);
    removeElementAt(pos);
}

template <class K>
void Container<K>::removeElementAt(Iterator pos){
    delete vector[pos.index];
    moveBackward(pos.index);
}

template <class K>
void Container<K>::insertElementAt(const K& item, Iterator pos){
    moveForward(pos.index);
    vector[pos.index] = new CItem(item);
}

template <class K>
int Container<K>::position(const K& item) const{
    bool found = false;
    int pos = -1;
    for(int i = 0; !found && i < size; i++){
        if(item == vector[i]->info){
            found = true;
            pos = i;
        }
    }
    return pos;
}

template <class K>
typename Container<K>::Iterator Container<K>::indexOf(const K& item){
    return position(item);
}

template <class K>
typename Container<K>::ConstIterator Container<K>::indexOf(const K& item) const {
    return position(item);
}

template <class K>
bool Container<K>::contains(const K& item) const {
    bool found = false;
    for(int i = 0; !found && i < size; i++){
        if(item == vector[i]->info)
            found = true;
    }
    return found;
}

#endif // CONTAINER_H

