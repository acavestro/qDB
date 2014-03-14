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


private slots:
    void on_btnSearch_clicked();
    void on_tblSearchResult_cellDoubleClicked(int row, int column);

    void on_btnResetFields_clicked();

private:
    Ui::DialogSearchAccount *ui;
    ElencoConti* el;
    Container<ElencoConti::ContoPtr&>* searchResult;
    bool populateTable();
};

#endif // DIALOGSEARCHACCOUNT_H
