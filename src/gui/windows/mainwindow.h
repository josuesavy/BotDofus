#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QVariant>
#include <QSystemTrayIcon>
#include <QProgressDialog>

#include "src/core/process/ProcessEngine.h"

#include "dialogs/accountmanager/accountmanagerdialog.h"
#include "forms/accountform.h"
#include "src/gui/utils/delegate/qtreewidgetitemdelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void remove(AccountForm *accountForm, bool child=false);

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void closeAccountManagerDialog();

private slots:
    void addAccount(const QList<ConnectionInfos> &accounts);
    void updateBotInferface(SocketIO *sender);

    void on_actionQuit_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAccountManager_triggered();

    void on_treeWidgetAccount_itemClicked(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemActivated(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemEntered(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemPressed(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemCollapsed(QTreeWidgetItem *item);
    void on_treeWidgetAccount_itemExpanded(QTreeWidgetItem *item);
    void on_treeWidgetAccount_itemSelectionChanged();

    void on_actionConnectAllLoadedAccounts_triggered();
    void on_actionDisconnectAllLoadedAccounts_triggered();
    void on_actionUnloadAllLoadedAccounts_triggered();
    void on_actionLoadScriptAllLoadedAccounts_triggered();
    void on_actionRunScriptAllLoadedAccounts_triggered();
    void on_actionStopScriptAllLoadedAccounts_triggered();

private:
    Ui::MainWindow *ui;

    AccountManagerDialog *accountManagerDialog;

    ProcessEngine m_engine;

    QList<AccountForm*> m_accountForms;

    QList<QTreeWidgetItem*> getTreeWidgetItems();
};

#endif // MAINWINDOW_H
