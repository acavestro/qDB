#ifndef CONTAINER_H
#define CONTAINER_H

#define LOAD_TO_EXPAND 1
#define EXPANSION_FACTOR 2
#define LOAD_TO_SHRINK 0.25
#define SHRINK_FACTOR 0.5

/*********** DICHIARAZIONI ***********/
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
    Container(int =10);
    Container(const Container&);
    Container& operator=(const Container&);
    ~Container();
    void push_back(const K&);
    bool isEmpty() const;
    int getSize() const;
    int getCapacity() const;
    K& pop_back();


    class Iterator;

    class ConstIterator {
        friend class Container;
    private:
        int index;
        CItem** base;
        ConstIterator(int, CItem**);
    public:
        ConstIterator(int = 0);
        ConstIterator(const Iterator&);
        bool operator==(const ConstIterator&) const;
        bool operator!=(const ConstIterator&) const;
        const K& operator*() const;
        const K* operator->() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator& operator--();
        ConstIterator operator--(int);
    };

    class Iterator {
        friend class Container;
    private:
        int index;
        CItem** base;
        Iterator(int, CItem**);
    public:
        Iterator(int =0);
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;
        K& operator*();
        K* operator->();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
    };

    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    const K& operator[](ConstIterator) const;
    K& operator[](Iterator);
    void removeElement(const K&);
    void removeElementAt(Iterator);
    void insertElementAt(const K&, Iterator);
    Iterator indexOf(const K&);
    ConstIterator indexOf(const K&) const;
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

template <class K>
typename Container<K>::CItem** Container<K>::clone() const {
    CItem** vc = new CItem*[size];
    for(int i = 0; i < size; i++){
        vc[i] = new CItem(vector[i]->info);
    }
    return vc;
}

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
    int pos;
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

