#include "dialogeditaccount.h"
#include "ui_dialogeditaccount.h"
#include "QMessageBox"
#include "QDebug"

DialogEditAccount::DialogEditAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditAccount)
{
    ui->setupUi(this);
    ui->cmbOpType->insertItem(PICKUP, "Prelievo");
    ui->cmbOpType->insertItem(DEPOSIT, "Deposito");
}

DialogEditAccount::~DialogEditAccount()
{
    delete ui;
}

void DialogEditAccount::bindData(Container<ElencoConti::ContoPtr>::Iterator it, ElencoConti* ec){
    itAccount = it;
    elenco = ec;
    //account = elenco->getAccount(itAccount);
    populateDialog();

}

void DialogEditAccount::populateDialog(){
    ElencoConti::ContoPtr& acc = elenco->getAccount(itAccount);
    ui->lblAccountType->setText(QString::fromStdString(acc->getTipoConto()));
    loadBalance();
    ui->txtEditName->setText(QString::fromStdString(acc->getNome()));
    ui->txtEditSurname->setText(QString::fromStdString(acc->getCognome()));
}

void DialogEditAccount::loadBalance(){
    ElencoConti::ContoPtr& acc = elenco->getAccount(itAccount);
    ui->lblBalance->setText(QString::number(acc->getSaldo()));
    if(acc->getSaldo() < 0){
        ui->lblBalance->setStyleSheet("color: red;");
    } else {
        ui->lblBalance->setStyleSheet("color: black;");
    }
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
    ElencoConti::ContoPtr& acc = elenco->getAccount(itAccount);
    acc->setNome(newName.toStdString());
    acc->setCognome(newSurname.toStdString());
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
    if(isAmountADouble && amount >= 0){
        ElencoConti::ContoPtr& acc = elenco->getAccount(itAccount);
        int opType = ui->cmbOpType->currentIndex();
        if(opType == PICKUP){
            double previousBalance = acc->getSaldo();
            double newBalance = acc->preleva(amount);
            if(previousBalance == newBalance){
                QMessageBox err;
                err.setText("Saldo insufficiente per completare l'operazione");
                err.exec();
                return false;
            }
        } else if (opType == DEPOSIT){
            acc->deposita(amount);
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
    if(result){
        populateDialog();
        emit operationMaked();
        //qDebug() << "Signal operationMaked() emesso" << endl;
    }
}

void DialogEditAccount::on_btnDeleteAccount_clicked()
{
    int reply = QMessageBox::question(this, "Cancellazione conto", "Confermi la cancellazione del conto?",
                                  QMessageBox::Yes, QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
        elenco->deleteAccount(itAccount);
        emit accountChanged();
        this->close();
    }

}
