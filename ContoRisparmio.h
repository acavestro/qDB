#ifndef CONTORISPARMIO_H
#define CONTORISPARMIO_H
#include <ContoBancario.h>
#include <string>
using std::string;

/**
 * @brief Classe ContoRisparmio.
 * Modella un ContoBancario senza commissioni e senza
 * possibilità di saldo negativo.
 */
class ContoRisparmio: virtual public ContoBancario
{
public:
    /**
     * @brief Costruttore di default.
     */
    ContoRisparmio();
    /**
     * @brief Costruttore che chiede un nome e un cognome (passati come string)
     * e un saldo iniziale, di default pari a zero.
     */
    ContoRisparmio(string, string, double = 0);
    /**
     * @brief Costruttore di copia
     */
    ContoRisparmio(const ContoRisparmio&);
    //metodi virtuali
    /**
     * @brief Preleva dal ContoRisparmio se e solo se la cifra da prelevare
     * è inferiore o al più uguale al saldo attuale, in mondo che quest'ultimo
     * non diventi mai negativo.
     * @return Un valore double pari al saldo dopo l'operazione di prelievo,
     * se l'operazione va a buon fine, altrimenti restituisce un valore pari
     * al saldo prima della chiamata alla funzione.
     */
    double preleva(double);
    /**
     * @brief Clona l'oggetto d'istanza sullo heap. ATTENZIONE AL GARBAGE.
     * @return Un puntatore ContoRisparmio* all'oggetto creato.
     * @return
     */
    ContoRisparmio* clona() const;
    /**
     * @brief Rappresentazione su stringa
     * @return Un valore di tipo string contenente una rappresentazione
     * del ContoRisparmio.
     */
    string toString() const;
    /**
     * Operatore di uguaglianza.
     */
    bool operator==(const ContoBancario&) const;
    /**
     * Tipologia di conto.
     */
    string getTipoConto() const;
};

#endif // CONTORISPARMIO_H
