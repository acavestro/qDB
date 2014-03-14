#include "dialogeditaccount.h"
#include "ui_dialogeditaccount.h"
#include "QMessageBox"

DialogEditAccount::DialogEditAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditAccount)
{
    ui->setupUi(this);
}

DialogEditAccount::~DialogEditAccount()
{
    delete ui;
}

void DialogEditAccount::bindAccount(ElencoConti::ContoPtr* c){
    account = c;
    populateDialog();
}

void DialogEditAccount::populateDialog(){
    ui->lblAccountType->setText(QString::fromStdString((*account)->getTipoConto()));
    ui->txtEditName->setText(QString::fromStdString((*account)->getNome()));
    ui->txtEditSurname->setText(QString::fromStdString((*account)->getCognome()));
    ui->cmbOpType->insertItem(PICKUP, "Prelievo");
    ui->cmbOpType->insertItem(DEPOSIT, "Deposito");
}

bool DialogEditAccount::editAccountOwner(){
    QString newName = ui->txtEditName->text();
    QString newSurname = ui->txtEditSurname->text();
    if(!newName.size() || !newSurname.size()){
        QMessageBox err;
        err.setText("I campi dati non possono essere impostati a valori vuoti");
        err.exec();
        return false;
    }
    (*account)->setNome(newName.toStdString());
    (*account)->setCognome(newSurname.toStdString());
    QMessageBox dlg;
    dlg.setText("Dati intestatario modificati con successo");
    dlg.exec();
    emit accountChanged();
    return true;
}

void DialogEditAccount::on_btnEditAccountOwner_clicked()
{
    editAccountOwner();
}

bool DialogEditAccount::operation(){
    bool isAmountADouble;
    double amount = ui->txtAmount->text().toDouble(&isAmountADouble);
    if(isAmountADouble){
        int opType = ui->cmbOpType->currentIndex();
        if(opType == PICKUP){
            double previousBalance = (*account)->getSaldo();
            double newBalance = (*account)->preleva(amount);
            if(previousBalance == newBalance){
                QMessageBox err;
                err.setText("Saldo insufficiente per completare l'operazione");
                err.exec();
                return false;
            }
        } else if (opType == DEPOSIT){
            (*account)->deposita(amount);
        } else {
            QMessageBox err;
            err.setText("Si è verificato un errore nell'esecuzione dell'operazione");
            err.exec();
            return false;
        }
        QMessageBox dlg;
        dlg.setText("Operazione eseguita con successo");
        dlg.exec();
        return true;
    } else {
        QMessageBox err;
        err.setText("Il campo importo non contiene un valore corretto");
        err.exec();
        return false;
    }
}

void DialogEditAccount::on_btnExecute_clicked()
{
    bool result = operation();
    if(result)
        emit operationMaked();
}
