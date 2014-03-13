#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddaccount.h"
#include "dialogsearchaccount.h"
#include "QInputDialog"
#include "QString"
#include "iostream"
#include <ContoBancario.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    elenco(new ElencoConti)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("qDB v1.0 - Programmazione a Oggetti 2013/2014 @ UniPD - Antonio Cavestro");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAddAccount_clicked()
{
    DialogAddAccount* daa = new DialogAddAccount;
    daa->bindElenco(elenco);
    daa->show();
}

void MainWindow::on_btnSearchAccount_clicked()
{
    DialogSearchAccount *dsa = new DialogSearchAccount;
    dsa->bindElenco(elenco);
    dsa->show();
}
