#ifndef CONTOBANCARIO_H
#define CONTOBANCARIO_H
#include <string>
using std::string;

class ContoBancario
{
public:
    ContoBancario(string, string, double = 0);
    ContoBancario(const ContoBancario&);
    string getNome() const;
    string getCognome() const;
    double getSaldo() const;
    void setNome(string);
    void setCognome(string);
    //metodi virtuali
    virtual ~ContoBancario();
    virtual double preleva(double);
    virtual double deposita(double);
    virtual ContoBancario* clona() const;
    virtual string toString() const;
    virtual bool operator==(const ContoBancario&) const;
private:
    double saldo;
    string nome;
    string cognome;
};

#endif // CONTOBANCARIO_H
