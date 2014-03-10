#include "dialogaddaccount.h"
#include "ui_dialogaddaccount.h"
#include "QMessageBox"

DialogAddAccount::DialogAddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAccount)
{
    ui->setupUi(this);
}

DialogAddAccount::~DialogAddAccount()
{
    delete ui;
}

void DialogAddAccount::on_buttonBox_accepted()
{
   QMessageBox prova;
   prova.setText("Vuoi creare un nuovo conto, eh?");
   prova.exec();

   this->close();
}
