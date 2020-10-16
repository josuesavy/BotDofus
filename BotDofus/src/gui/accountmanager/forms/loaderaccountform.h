#ifndef LOADERACCOUNTFORM_H
#define LOADERACCOUNTFORM_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QProgressDialog>
#include <QtSql/QtSql>
#include <QFileDialog>

#include "src/Engines/Core/CoreEngine.h"
#include "src/Public.h"

namespace Ui {
class LoaderAccountForm;
}

class LoaderAccountForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoaderAccountForm(QWidget *parent = nullptr);
    ~LoaderAccountForm();

public slots:
    void initialization();

signals:
    void updateListAccounts();
    void loadAccount(const QList<ConnectionInfos>&);

private slots:
    void on_treeWidgetAccounts_itemSelectionChanged();
    void on_treeWidgetAccounts_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccounts_itemChanged(QTreeWidgetItem *item, int column);

    void on_pushButtonImportAccounts_clicked();
    void on_pushButtonExportAccounts_clicked();
    void on_pushButtonDelete_clicked();

    void on_pushButtonLoad_clicked();

private:
    Ui::LoaderAccountForm *ui;

    QList<ConnectionInfos> m_accounts;
};

#endif // LOADERACCOUNTFORM_H
