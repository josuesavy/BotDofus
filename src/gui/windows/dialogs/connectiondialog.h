#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QDir>
#include <QtSql/QtSql>
#include <QSemaphore>

#include "mainwindow.h"
#include "ThreadInitGameData.h"

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();

    void showEvent(QShowEvent *event);

public slots:
    void updateInterface(int value, QString message);
    void threadFinished();

private slots:
    void on_lineEditPathDofus_textChanged(const QString &arg1);
    void on_pushButtonBrowser_clicked();
    void on_pushButtonConnect_clicked();

    void init();

private:
    Ui::ConnectionDialog *ui;

    QString m_path;
    QString D2O;
    QString D2P;
    QString I18N;

    ThreadInitGameData *threadInitGameData;
    QSemaphore semaphore;

    QList<ConnectionInfos> m_accounts;

    QSqlDatabase m_db;
};

#endif // CONNECTIONDIALOG_H
