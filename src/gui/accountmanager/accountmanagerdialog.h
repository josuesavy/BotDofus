#ifndef ACCOUNTMANAGERDIALOG_H
#define ACCOUNTMANAGERDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>

#include "src/Engines/Core/CoreEngine.h"
#include "forms/loaderaccountform.h"
#include "forms/addaccountform.h"
#include "forms/charactercreatorform.h"
#include "forms/configurationform.h"

namespace Ui {
class AccountManagerDialog;
}

class AccountManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountManagerDialog(QWidget *parent = nullptr);
    ~AccountManagerDialog();

public slots:
    void closeAfterLoaded();

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void loadAccount(const QList<ConnectionInfos>&);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AccountManagerDialog *ui;

    LoaderAccountForm *loaderAccountForm;
    AddAccountForm *addAccountForm;
    CharacterCreatorForm *characterCreatorForm;
};

#endif // ACCOUNTMANAGERDIALOG_H
