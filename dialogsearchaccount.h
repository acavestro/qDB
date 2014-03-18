#ifndef DIALOGSEARCHACCOUNT_H
#define DIALOGSEARCHACCOUNT_H
#include <ElencoConti.h>
#include <Container.h>
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
    void openConto(int);

signals:
    void infoElencoChanged();

private slots:
    void on_btnSearch_clicked();
    void on_tblSearchResult_cellDoubleClicked(int row, int column);
    void on_btnResetFields_clicked();
    void onAccountChanged();


private:
    Ui::DialogSearchAccount *ui;
    ElencoConti* el;
    Container<Container<ElencoConti::ContoPtr>::Iterator> searchResult;
    int numResult;
    bool populateTable();
    void clearTable();
};

#endif // DIALOGSEARCHACCOUNT_H
