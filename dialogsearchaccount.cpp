#include "dialogsearchaccount.h"
#include "ui_dialogsearchaccount.h"
#include "QString"
#include "QMessageBox"
#include "QSignalMapper"
#include "QDebug"
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
    delete searchResult;
    delete ui;
}

void DialogSearchAccount::bindElenco(ElencoConti * e){
    el = e;
    populateTable();
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
        delete searchResult;
        searchResult = new Container<ElencoConti::ContoPtr&>(el->search(name.toStdString(),
                                                                        surname.toStdString(),
                                                                        balancePattern.toStdString(),
                                                                        balance));
        if (searchResult->getSize() > 0){
            int row = 0, col;

            for(Container<ElencoConti::ContoPtr&>::Iterator it = searchResult->begin(); it != searchResult->end(); it++){
                //ElencoConti::ContoPtr& cp = c[it];
                ui->tblSearchResult->setRowCount(row+1);
                col = 0;

                QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString((*searchResult)[it]->getTipoConto()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(row, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::fromStdString((*searchResult)[it]->getNome()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(row, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::fromStdString((*searchResult)[it]->getCognome()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(row, col, newItem);
                col++;

                newItem = new QTableWidgetItem(QString::number((*searchResult)[it]->getSaldo()));
                newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                ui->tblSearchResult->setItem(row, col, newItem);
                col++;

                //QPushButton* btn = new QPushButton("Modifica");
                //connect(btn, SIGNAL(clicked()), this, SLOT(on_btnModifica_clicked()));
                //ui->tblSearchResult->setCellWidget(row, col, btn);
                //col++;
                row++;
            }
        } else {
            /*
            QMessageBox dlg;
            dlg.setText("Nessun elemento trovato!");
            dlg.exec();
            */
            return false;
        }
    }
    return true;
}

void DialogSearchAccount::openConto(int row){
    int rCont = 0;
    Container<ElencoConti::ContoPtr&>::Iterator it;
    for(it = searchResult->begin(); rCont < row && it != searchResult->end(); it++){
        rCont++;
    }
    QMessageBox dlg;
    //dlg.setText(QString::fromStdString(cp->getNome()));
    dlg.setText(QString::fromStdString((*searchResult)[it]->getNome()));
    dlg.exec();

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
