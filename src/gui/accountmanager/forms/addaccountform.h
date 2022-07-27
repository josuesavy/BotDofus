#ifndef ADDACCOUNTFORM_H
#define ADDACCOUNTFORM_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtSql/QtSql>

#include "src/engines/core/CoreEngine.h"

namespace Ui {
class AddAccountForm;
}

class AddAccountForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddAccountForm(QWidget *parent = nullptr);
    ~AddAccountForm();

signals:
    void updateListAccounts();

private slots:
    void on_pushButtonAddAccount_clicked();

    void on_pushButtonRefreshAccountName_clicked();

    void on_pushButtonRefreshPassword_clicked();

    void on_pushButtonRefreshEmail_clicked();

    void on_pushButtonRefreshNickname_clicked();

    void on_pushButtonLockAccountName_clicked(bool checked);

    void on_pushButtonLockPassword_clicked(bool checked);

    void on_pushButtonLockEmail_clicked(bool checked);

    void on_pushButtonLockNickname_clicked(bool checked);

    void on_pushButtonRefreshGlobal_clicked();

    void on_lineEditAccountName_textChanged(const QString &arg1);

    void onfinish(QNetworkReply*reply);

private:
    Ui::AddAccountForm *ui;

    QString getRandomString(int size = 8);
};

#endif // ADDACCOUNTFORM_H
