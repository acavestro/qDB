#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddaccount.h"
#include "dialogsearchaccount.h"
#include "QInputDialog"
#include "QString"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    elenco(new ElencoConti)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("qDB v1.0 - Programmazione a Oggetti 2013/2014 @ UniPD - Antonio Cavestro");
    ui->lblCommDepCC->setText(QString::number(ElencoConti::getCommissioneDepositoCC()) + " €");
    ui->lblCommPrelCC->setText(QString::number(ElencoConti::getCommissionePrelievoCC()) + " €");
    loadElencoContiInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadElencoContiInfo(){
    ui->lblTotConti->setText(QString::number(elenco->getNumConti()));
    ui->lblSaldoTot->setText(QString::number(elenco->getSaldoTotale()) + " €");
    if(elenco->getSaldoTotale() < 0){
        ui->lblSaldoTot->setStyleSheet("color:red;");
    } else {
        ui->lblSaldoTot->setStyleSheet("color:black;");
    }
}


void MainWindow::on_btnAddAccount_clicked()
{
    DialogAddAccount* daa = new DialogAddAccount;
    daa->bindElenco(elenco);
    connect(daa, SIGNAL(newAccountAdded()), this, SLOT(onReloadInfoConti()));
    daa->show();
}

void MainWindow::on_btnSearchAccount_clicked()
{
    DialogSearchAccount *dsa = new DialogSearchAccount;
    dsa->bindElenco(elenco);
    connect(dsa, SIGNAL(infoElencoChanged()), this, SLOT(onReloadInfoConti()));
    dsa->show();
}

void MainWindow::onReloadInfoConti(){
    loadElencoContiInfo();
}
