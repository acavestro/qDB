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
    enum RB_TYPEACCOUNT_ID {
        CBANCARIO_ID, CCORRENTE_ID, CRISPARMIO_ID
    };
    void bindElenco(ElencoConti*);

signals:
    void newAccountAdded();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::DialogAddAccount *ui;
    ElencoConti* el;
    void setupInserimento();
    bool addConto();
};

#endif // DIALOGADDACCOUNT_H
