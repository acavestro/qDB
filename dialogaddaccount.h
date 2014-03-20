#ifndef DIALOGADDACCOUNT_H
#define DIALOGADDACCOUNT_H
#include <ElencoConti.h>
#include <QDialog>

namespace Ui {
class DialogAddAccount;
}

class DialogAddAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddAccount(QWidget *parent = 0);
    ~DialogAddAccount();
    /**
     * Collega l'ElencoConti alla finestra d'inserimento.
     * Necessario per poter aggiungere conti.
     */
    void bindElenco(ElencoConti*);

signals:
    /**
     * Segnale emesso quando un nuovo conto viene creato.
     */
    void newAccountAdded();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::DialogAddAccount *ui;
    ElencoConti* el;
    enum RB_TYPEACCOUNT_ID {
        CBANCARIO_ID, CCORRENTE_ID, CRISPARMIO_ID
    };
    void setupInserimento();
    bool addConto();
};

#endif // DIALOGADDACCOUNT_H
