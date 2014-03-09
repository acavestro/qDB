#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <ContoBancario.h>
#include <string>
using std::string;

/**
 * @brief Classe ContoCorrente.
 * Modella un ContoBancario in cui sono previste
 * commissioni su prelievo e deposito e possibilità
 * di saldo negativo.
 */
class ContoCorrente: public ContoBancario
{
public:
    /**
     * @brief Costruttore che chiede un nome e un cognome (passati come string)
     * e un saldo iniziale, di default pari a zero.
     */
    ContoCorrente(string, string, double = 0);
    /**
     * @brief Costruttore di copia
     */
    ContoCorrente(const ContoCorrente&);
    //metodi virtuali
    /**
     * @brief Preleva dal ContoCorrente il valore double passato come
     * parametro più il valore della commissione sui prelievi.
     * @return Un valore double pari al saldo dopo l'operazione di prelievo
     */
    double preleva(double);
    /**
     * @brief Deposita sul ContoCorrente il valore double passato
     * come parametro meno il valore della commissione sui depositi.
     * @return Un valore double pari al saldo dopo l'operazione di deposito
     */
    double deposita(double);
    /**
     * @brief Clona l'oggetto d'istanza sullo heap. ATTENZIONE AL GARBAGE.
     * @return Un puntatore ContoCorrente* all'oggetto creato.
     */
    ContoCorrente* clona() const;
    /**
     * @brief Rappresentazione su stringa
     * @return Un valore di tipo string contenente una rappresentazione
     * del ContoCorrente.
     */
    string toString() const;
private:
    static double commissionePrelievo;
    static double commissioneDeposito;
};

#endif // CONTOCORRENTE_H
