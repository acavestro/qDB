#ifndef DIALOGADDACCOUNT_H
#define DIALOGADDACCOUNT_H

#include <QDialog>

namespace Ui {
class DialogAddAccount;
}

class DialogAddAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddAccount(QWidget *parent = 0);
    ~DialogAddAccount();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddAccount *ui;
};

#endif // DIALOGADDACCOUNT_H
