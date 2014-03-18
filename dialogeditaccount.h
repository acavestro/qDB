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
    void bindData(Container<ElencoConti::ContoPtr>::Iterator, ElencoConti*);
    void bindElenco(ElencoConti*);

signals:
    void accountChanged();
    void operationMaked();

private slots:
    void on_btnEditAccountOwner_clicked();

    void on_btnExecute_clicked();

    void on_btnDeleteAccount_clicked();

private:
    Ui::DialogEditAccount *ui;
    Container<ElencoConti::ContoPtr>::Iterator itAccount;
    //ElencoConti::ContoPtr* account;
    ElencoConti* elenco;
    enum CB_TYPE_OPERATION_ID { PICKUP, DEPOSIT };
    void populateDialog();
    void loadBalance();
    bool editAccountOwner();
    bool operation();
};

#endif // DIALOGEDITACCOUNT_H
