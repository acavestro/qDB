#include "dialogaddaccount.h"
#include "ui_dialogaddaccount.h"
#include "QMessageBox"
#include "QString"
#include "QDebug"

DialogAddAccount::DialogAddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAccount)
{
    ui->setupUi(this);
    setupInserimento();
}

void DialogAddAccount::setupInserimento(){
    ui->btnGrpAccountType->setId(ui->radioBancario, CBANCARIO_ID);
    ui->btnGrpAccountType->setId(ui->radioCorrente, CCORRENTE_ID);
    ui->btnGrpAccountType->setId(ui->radioRisparmio, CRISPARMIO_ID);
}

void DialogAddAccount::bindElenco(ElencoConti* e){
    el = e;
}

DialogAddAccount::~DialogAddAccount()
{
    delete ui;
}

bool DialogAddAccount::addConto(){
    //test sull'input
    bool isTxtBalanceADouble;
    QString name = ui->txtName->text();
    QString surname = ui->txtSurname->text();
    double balance = ui->txtBalance->text().toDouble(&isTxtBalanceADouble);
    if(name == "" || surname == "" || !isTxtBalanceADouble){
        QMessageBox err;
        err.setText("Sembra che i dati del conto non siano corretti..");
        err.exec();
        return false;
    } else {
        int typeAccount = ui->btnGrpAccountType->checkedId();
        bool notAdmitDuplicates = ui->chkDontAdmitDuplicates->isChecked();
        if(typeAccount == CBANCARIO_ID && notAdmitDuplicates)
            el->addNewContoBancarioIfNotPresent(name.toStdString(), surname.toStdString(), balance);
        else if(typeAccount == CBANCARIO_ID && !notAdmitDuplicates)
            el->addNewContoBancario(name.toStdString(), surname.toStdString(), balance);
        else if(typeAccount == CCORRENTE_ID && notAdmitDuplicates)
            el->addNewContoCorrenteIfNotPresent(name.toStdString(), surname.toStdString(), balance);
        else if(typeAccount == CCORRENTE_ID && !notAdmitDuplicates)
            el->addNewContoCorrente(name.toStdString(), surname.toStdString(), balance);
        else if(typeAccount == CRISPARMIO_ID && notAdmitDuplicates && balance >=0)
            el->addNewContoRisparmioIfNotPresent(name.toStdString(), surname.toStdString(), balance);
        else if(typeAccount == CRISPARMIO_ID && !notAdmitDuplicates && balance >=0)
            el->addNewContoRisparmio(name.toStdString(), surname.toStdString(), balance);
        else {
            QMessageBox err;
            err.setText("Si è verificato qualche problema con l'inserimento. Il conto non è stato creato");
            err.exec();
            return true;
        }
        QMessageBox info;
        info.setText("Conto creato e salvato con successo!");
        info.exec();
        return false;
    }
}

void DialogAddAccount::on_buttonBox_accepted()
{
    addConto();
}

