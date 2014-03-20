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
     * Rappresenta l'interfaccia per accedere a un generico Conto Bancario.
     * Modella un puntatore smart a un ContoBancario.
     */
    class ContoPtr {
    private:
        ContoBancario* punt;
    public:
        /**
         * Costruttore di default. Permette la conversione
         * ContoBancario* => ContoPtr.
         */
        ContoPtr(ContoBancario* =0);
        /**
         * Costruttore di copia. Effettua una copia profonda.
         */
        ContoPtr(const ContoPtr&);
        /**
         * Distruttore. Si occupa si deallocare il conto
         * allocato sullo heap.
         */
        ~ContoPtr();
        /**
         * Operatore di assegnazione. Effettua una copia
         * profonda.
         */
        ContoPtr& operator=(const ContoPtr&);
        /**
         * Operatore di uguaglianza.
         */
        bool operator==(const ContoPtr&) const;
        /**
         * Operatore di disuguaglianza.
         */
        bool operator!=(const ContoPtr&) const;
        /**
         * Operatore di dereferenziazione. Permette
         * il side-effect sul conto puntato.
         */
        ContoBancario& operator*();
        /**
         * Operatore di dereferenziazione. Non permette
         * il side-effect sul conto puntato.
         */
        const ContoBancario& operator*() const;
        /**
         * Operatore di accesso a membro. Permette il
         * side-effect sull'oggetto puntato.
         */
        ContoBancario* operator->();
        /**
         * Operatore di accesso a membro. Non permette il
         * side-effect sull'oggetto puntato.
         */
        const ContoBancario* operator->() const;
        /**
         * Test sul nome dell'intestatario del conto. Accetta
         * la wildcard "*".
         */
        bool hasThisName(string = "*") const;
        /**
         * Test sul cognome dell'intestatario del conto. Accetta
         * la wildcard "*".
         */
        bool hasThisSurname(string ="*") const;
        /**
         * Test sul saldo del conto. Accetta la wildcard "*" e i
         * confronti =, >, >=, <, <=.
         */
        bool hasThisBalance(double, string = "*") const;
    };
    /**
     * @brief Costruttore di default. Crea un nuovo elenco,
     * e alloca sullo heap un nuovo contenitore di conti.
     */
    ElencoConti();
    /**
     * @brief Distruttore
     */
    ~ElencoConti();
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
     * Ricerca all'interno dell'elenco. Permette di fare ricerche per
     * nome intestatario, cognome intestatario e saldo. È possibile
     * utilizzare la wildcard "*" su tutti i campi e cercare sui saldi
     * in base a valori =, <, <=, >, >=.
     * @return Un Container di Iterator ai conti dell'elenco che puntano
     * ai risultati della ricerca.
     */
    Container<Container<ElencoConti::ContoPtr>::Iterator> search(string ="*", string="*", string="*", double=0.0) const;
    /**
     * Commissione di prelievo sui Conti Correnti.
     */
    static double getCommissionePrelievoCC();
    /**
     * Commissione di deposito sui Conti Correnti.
     */
    static double getCommissioneDepositoCC();
    /**
     * Numero di conti contenuti nell'elenco.
     */
    int getNumConti() const;
    /**
     * Somma dei saldi di tutti i conti contenuti nell'elenco.
     */
    double getSaldoTotale() const;
    /**
     * Accesso a un conto tramite un Iteratore.
     * @return Un oggetto di tipo ContoPtr che punta al conto bancario
     * indicato dall'Iterator.
     */
    ContoPtr& getAccount(Container<ElencoConti::ContoPtr>::Iterator);

private:
    Container<ContoPtr>* elenco;
};

#endif // ELENCOCONTI_H
