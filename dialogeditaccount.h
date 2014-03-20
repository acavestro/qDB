#ifndef DIALOGEDITACCOUNT_H
#define DIALOGEDITACCOUNT_H
#include "ElencoConti.h"
#include "Container.h"
#include <QDialog>

namespace Ui {
class DialogEditAccount;
}

class DialogEditAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditAccount(QWidget *parent = 0);
    ~DialogEditAccount();
    /**
     * Collega un ElencoConti e un Iterator all'elemento da modificare.
     * Necessario per poter effettuare modifiche e rimozione.
     */
    void bindData(Container<ElencoConti::ContoPtr>::Iterator, ElencoConti*);

signals:
    /**
     * Segnale emesso quando un account subisce modifiche.
     */
    void accountChanged();
    /**
     * Segnale emesso quando un'operazione (prelievo o deposito)
     * viene eseguita.
     */
    void operationMaked();

private slots:
    void on_btnEditAccountOwner_clicked();
    void on_btnExecute_clicked();
    void on_btnDeleteAccount_clicked();

private:
    Ui::DialogEditAccount *ui;
    Container<ElencoConti::ContoPtr>::Iterator itAccount;
    ElencoConti* elenco;
    enum CB_TYPE_OPERATION_ID { PICKUP, DEPOSIT };
    void populateDialog();
    void loadBalance();
    bool editAccountOwner();
    bool operation();
};

#endif // DIALOGEDITACCOUNT_H
