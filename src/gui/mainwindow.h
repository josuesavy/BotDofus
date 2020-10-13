#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QVariant>
#include <QSystemTrayIcon>
#include <QProgressDialog>

#include "src/Engines/Core/Process/ProcessEngine.h"

#include "accountmanager/accountmanagerdialog.h"
#include "main/accountform.h"
#include "delegate/qtreewidgetitemdelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTrayMenu();

public slots:
    void remove(AccountForm *accountForm, bool child=false);

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void closeAccountManagerDialog();

private slots:
    void addAccount(const QList<ConnectionInfos> &accounts);
    void updateBotInferface(SocketIO *sender);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void on_actionQuit_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAccountManager_triggered();
    void on_actionMinimize_triggered();

    void on_treeWidgetAccount_itemClicked(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemActivated(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemEntered(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemPressed(QTreeWidgetItem *item, int column);
    void on_treeWidgetAccount_itemCollapsed(QTreeWidgetItem *item);
    void on_treeWidgetAccount_itemExpanded(QTreeWidgetItem *item);

private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *trayIcon;

    ProcessEngine m_engine;

    QList<AccountForm*> m_accountForms;

    QList<QTreeWidgetItem*> getTreeWidgetItems();
};

#endif // MAINWINDOW_H
