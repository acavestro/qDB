#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ElencoConti.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadElencoContiInfo();

private slots:
    void on_btnAddAccount_clicked();
    void on_btnSearchAccount_clicked();
    void onReloadInfoConti();

private:
    Ui::MainWindow *ui;
    ElencoConti *elenco;
};

#endif // MAINWINDOW_H
