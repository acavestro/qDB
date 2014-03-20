#include "dialogsearchaccount.h"
#include "ui_dialogsearchaccount.h"
#include "QString"
#include "QMessageBox"
#include "dialogeditaccount.h"
#include <Container.h>


DialogSearchAccount::DialogSearchAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSearchAccount),
    searchResult(0)
{
    ui->setupUi(this);
}

DialogSearchAccount::~DialogSearchAccount()
{
    delete ui;
}

void DialogSearchAccount::bindElenco(ElencoConti * e){
    el = e;
    populateTable();
}

void DialogSearchAccount::clearTable(){
    ui->tblSearchResult->setRowCount(0);
}

bool DialogSearchAccount::populateTable() {
    QString name = ui->txtName->text();
    QString surname = ui->txtSurname->text();
    QString balancePattern = ui->cmbBalancePattern->currentText();
    bool isBalanceADouble;
    double balance = ui->txtBalance->text().toDouble(&isBalanceADouble);
    if(!isBalanceADouble){
        QMessageBox err;
        err.setText("Il saldo non ha un valore corretto");
        err.exec();
        return false;
    } else {
        clearTable();
        searchResult = el->search(name.toStdString(), surname.toStdString(), balancePattern.toStdString(), balance);
        numResult = searchResult.getSize();
        if (numResult > 0){
            int col;

            for(int i = 0; i < numResult; i++){
                ElencoConti::ContoPtr& cp = el->getAccount(searchResult[i]);
                ui->tblSearchResult->setRowCount(i+1);
                col = 0;

                QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString(cp->getTipoConto()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(i, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::fromStdString(cp->getNome()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(i, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::fromStdString(cp->getCognome()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(i, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::number(cp->getSaldo()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(i, col, newItem);
                col++;
            }
        } else {
            return false;
        }
    }
    return true;
}

void DialogSearchAccount::openConto(int row){
    DialogEditAccount* dea = new DialogEditAccount;
    dea->bindData(searchResult[row], el);
    connect(dea, SIGNAL(accountChanged()), this, SLOT(onAccountChanged()));
    connect(dea, SIGNAL(operationMaked()), this, SLOT(onAccountChanged()));
    dea->show();

}

void DialogSearchAccount::on_btnSearch_clicked()
{
    bool res = populateTable();
    if(!res){
        QMessageBox dlg;
        dlg.setText("Nessun elemento trovato!");
        dlg.exec();
    }
}


void DialogSearchAccount::on_tblSearchResult_cellDoubleClicked(int row, int column)
{
    openConto(row);
}

void DialogSearchAccount::on_btnResetFields_clicked()
{
    ui->txtName->setText("*");
    ui->txtSurname->setText("*");
    ui->txtBalance->setText("0");
    ui->cmbBalancePattern->setCurrentIndex(0);
    if(ui->tblSearchResult->rowCount())
        ui->tblSearchResult->setRowCount(0);

}

void DialogSearchAccount::onAccountChanged(){
    populateTable();
    emit infoElencoChanged();
}
