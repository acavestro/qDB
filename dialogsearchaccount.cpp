#include "dialogsearchaccount.h"
#include "ui_dialogsearchaccount.h"
#include "QString"
#include "QMessageBox"
#include "QDebug"
#include <Container.h>

DialogSearchAccount::DialogSearchAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSearchAccount)
{
    ui->setupUi(this);
}

DialogSearchAccount::~DialogSearchAccount()
{
    delete ui;
}

void DialogSearchAccount::bindElenco(ElencoConti * e){
    el = e;
}

void DialogSearchAccount::on_btnSearch_clicked()
{
    QString name = ui->txtName->text();
    QString surname = ui->txtSurname->text();
    QString balancePattern = ui->cmbBalancePattern->currentText();
    bool isBalanceADouble;
    double balance = ui->txtBalance->text().toDouble(&isBalanceADouble);
    if(!isBalanceADouble){
        //qDebug() << "Perché diavolo non funziona la MsgBox???";
        QMessageBox err;
        err.setText("Il saldo non ha un valore corretto");
        err.exec();
    } else {
        /*Container<Container::ConstIterator> c;
        c = el->search(name.toStdString(), surname.toStdString(), balancePattern.toStdString(), balance);
        for(Container::ConstIterator it = c.begin(); it != c.end(); it++){
            ui->tblSearchResult->
        }*/
    }
}
