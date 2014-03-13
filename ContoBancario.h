#ifndef CONTOBANCARIO_H
#define CONTOBANCARIO_H
#include <string>
using std::string;

/**
 * @brief Classe ContoBancario.
 * Modella un ContoBancario con nessuna commissione e la possibilità
 * di saldo negativo.
 */
class ContoBancario
{
public:
    /**
     * @brief Costruttore di default.
     */
    ContoBancario();
    /**
     * @brief Costruttore che chiede un nome e un cognome (passati come string)
     * e un saldo iniziale, di default pari a zero.
     */
    ContoBancario(string, string, double = 0);
    /**
     * @brief Costruttore di copia
     */
    ContoBancario(const ContoBancario&);
    /**
     * @brief Restituisce il nome dell'intestatario.
     * @return Una stringa contenente il nome dell'intestatario
     * del ContoBancario.
     */
    string getNome() const;
    /**
     * @brief Restituisce il cognome dell'intestatario.
     * @return Una stringa contenente il cognome dell'intestatario
     * del ContoBancario.
     */
    string getCognome() const;
    /**
     * @brief Restituisce il saldo.
     * @return Un valore double contenente il saldo attuale del ContoBancario.
     */
    double getSaldo() const;
    /**
     * @brief Permette di cambiare il nome dell'intestatario.
     */
    void setNome(string);
    /**
     * @brief Permette di cambiare il cognome dell'intestatario.
     */
    void setCognome(string);
    //metodi virtuali
    /**
     * @brief Distruttore
     */
    virtual ~ContoBancario();
    /**
     * @brief Preleva dal ContoBancario il valore double passato come
     * parametro.
     * @return Un valore double pari al saldo dopo l'operazione di prelievo
     */
    virtual double preleva(double);
    /**
     * @brief Deposita sul ContoBancario il valore double passato
     * come parametro.
     * @return Un valore double pari al saldo dopo l'operazione di deposito
     */
    virtual double deposita(double);
    /**
     * @brief Clona l'oggetto d'istanza sullo heap. ATTENZIONE AL GARBAGE.
     * @return Un puntatore ContoBancario* all'oggetto creato.
     */
    virtual ContoBancario* clona() const;
    /**
     * @brief Rappresentazione su stringa
     * @return Un valore di tipo string contenente una rappresentazione
     * del ContoBancario.
     */
    virtual string toString() const;
    /**
     * @brief Operatore di uguaglianza
     * @return Un valore booleano pari a true se i valori di tutti i campi dati
     * del ContoBancario passato come riferimento costante sono uguali a
     * quelli dell'oggetto d'istanza, altrimenti false.
     */
    virtual bool operator==(const ContoBancario&) const;
    virtual string getTipoConto() const;
private:

    double saldo;
    string nome;
    string cognome;
};

#endif // CONTOBANCARIO_H
