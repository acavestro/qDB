#ifndef DIALOGSEARCHACCOUNT_H
#define DIALOGSEARCHACCOUNT_H
#include <ElencoConti.h>
#include <QDialog>

namespace Ui {
class DialogSearchAccount;
}

class DialogSearchAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearchAccount(QWidget *parent = 0);
    ~DialogSearchAccount();
    void bindElenco(ElencoConti*);

private slots:
    void on_btnSearch_clicked();

private:
    Ui::DialogSearchAccount *ui;
    ElencoConti* el;
};

#endif // DIALOGSEARCHACCOUNT_H
