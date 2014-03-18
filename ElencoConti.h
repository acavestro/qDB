#ifndef ELENCOCONTI_H
#define ELENCOCONTI_H
#include <Container.h>
#include <ContoBancario.h>
#include <ContoRisparmio.h>
#include <ContoCorrente.h>
#include <iostream>
using std::ostream;

/**
 * @brief Classe ElencoConti.
 * Incapsula le funzionalità di un contenitore di
 * ContiBancari, in particolare l'interfaccia di
 * "basso livello" con il Container.
 */
class ElencoConti
{
    /**
     * @brief Ridefinizione dell'operatore di output per
     * stampare un ElencoConti.
     */
    friend ostream& operator<<(ostream&, const ElencoConti&);
public:
    /**
     * @brief Classe ContoPtr.
     * Modella un puntatore smart a un ContoBancario.
     */
    class ContoPtr {
    private:
        ContoBancario* punt;
    public:
        ContoPtr(ContoBancario* =0);
        ContoPtr(const ContoPtr&);
        ~ContoPtr();
        ContoPtr& operator=(const ContoPtr&);
        bool operator==(const ContoPtr&) const;
        bool operator!=(const ContoPtr&) const;
        ContoBancario& operator*();
        const ContoBancario& operator*() const;
        ContoBancario* operator->();
        const ContoBancario* operator->() const;
        bool hasThisName(string = "*") const;
        bool hasThisSurname(string ="*") const;
        bool hasThisBalance(double, string = "*") const;
    };
    /**
     * @brief Costruttore di default. Crea un nuovo elenco,
     * e alloca sullo heap un nuovo contenitore di conti.
     */
    ElencoConti();
    /**
     * @brief Aggiunge un nuovo ContoBancario all'elenco
     */
    void addNewContoBancario(string, string, double =0);
    /**
     * @brief Aggiunge un nuovo ContoBancario all'elenco
     * se e solo se quest'ultimo non si trova già al
     * suo interno.
     */
    void addNewContoBancarioIfNotPresent(string, string, double =0);
    /**
     * @brief Aggiunge un nuovo ContoCorrente all'elenco
     */
    void addNewContoCorrente(string, string, double =0);
    /**
     * @brief Aggiunge un nuovo ContoCorrente all'elenco
     * se e solo se quest'ultimo non si trova già al
     * suo interno.
     */
    void addNewContoCorrenteIfNotPresent(string, string, double =0);
    /**
     * @brief Aggiunge un nuovo ContoRisparmio all'elenco
     */
    void addNewContoRisparmio(string, string, double =0);
    /**
     * @brief Aggiunge un nuovo ContoRisparmio all'elenco
     * se e solo se quest'ultimo non si trova già al
     * suo interno.
     */
    void addNewContoRisparmioIfNotPresent(string, string, double =0);
    /**
     * @brief Cancella un ContoBancario
     */
    void deleteAccount(ContoPtr&);
    /**
     * @brief Cancella dall'elenco il ContoBancario
     * puntato dall'iteratore passato come parametro.
     */
    void deleteAccount(Container<ContoPtr>::Iterator);
    /**
     * @brief Ricerca un elemento nell'elenco. In caso di
     * occorrenze multiple ritorna il primo.
     * @return Un oggetto di tipo ContoPtr che punta al primo elemento
     *  nell'elenco che corrisponde ai pattern passati come
     * parametri. Se non ci sono occorrenze ritorna 0;
     */
    //ContoPtr* searchSingleAccount(string ="*", string ="*", string = "*", double =0.0);
    Container<Container<ElencoConti::ContoPtr>::Iterator> search(string ="*", string="*", string="*", double=0.0) const;
    static double getCommissionePrelievoCC();
    static double getCommissioneDepositoCC();
    int getNumConti() const;
    double getSaldoTotale() const;
    ContoPtr* getAccount(Container<ElencoConti::ContoPtr>::Iterator);

private:
    Container<ContoPtr>* elenco;
};

#endif // ELENCOCONTI_H
