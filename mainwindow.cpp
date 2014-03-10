#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddaccount.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAddAccount_clicked()
{
    DialogAddAccount* daa = new DialogAddAccount;
    daa->show();
}
