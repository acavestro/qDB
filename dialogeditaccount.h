#ifndef DIALOGEDITACCOUNT_H
#define DIALOGEDITACCOUNT_H
#include "ElencoConti.h"
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
    void bindAccount(ElencoConti::ContoPtr*);

signals:
    void accountChanged();
    void operationMaked();

private slots:
    void on_btnEditAccountOwner_clicked();

    void on_btnExecute_clicked();

private:
    Ui::DialogEditAccount *ui;
    ElencoConti::ContoPtr* account;
    enum CB_TYPE_OPERATION_ID { PICKUP, DEPOSIT };
    void populateDialog();
    bool editAccountOwner();
    bool operation();
};

#endif // DIALOGEDITACCOUNT_H
