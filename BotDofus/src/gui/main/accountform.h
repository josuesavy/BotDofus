#ifndef ACCOUNTFORM_H
#define ACCOUNTFORM_H

#include <QWidget>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QStackedWidget>

#include "src/gui/main/forms/consoleform.h"
#include "src/gui/main/forms/characterform.h"
#include "src/gui/main/forms/inventoryform.h"
#include "src/gui/main/forms/mapform.h"
#include "src/gui/main/forms/floodform.h"
#include "src/gui/main/forms/fightform.h"
#include "src/gui/main/forms/settingsform.h"
#include "src/gui/main/forms/statisticsform.h"

#include "src/engines/core/process/ProcessEngine.h"
#include "src/engines/DataHandler.h"
#include "src/engines/utils/Logger/LogOutput.h"

namespace Ui {
class AccountForm;
}

class AccountForm : public QWidget
{
    Q_OBJECT

public:
    explicit AccountForm(ProcessEngine *engine, const ConnectionInfos &infos, QWidget *parent = nullptr);
    ~AccountForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos();
    ProcessEngine *getEngine();

    const BotData &getData() const;

    ConsoleForm *getConsoleForm();
    CharacterForm *getCharacterForm();
    InventoryForm *getInventoryForm();
    MapForm *getMapForm();
    FloodForm *getFloodForm();
    FightForm *getFightForm();
    SettingsForm *getSettingsForm();

    QList<AccountForm*> getAccountFormChilds();
    void setAccountFormChilds(QList<AccountForm*> accountForms);

    void loadScript(QString path);
    int loadPath(QString path, bool unload);

    void autoConnect();

signals:
    void remove(AccountForm *accountForm, bool child = false);

public slots:
    void updateInterface();

    void on_actionLoadScript_triggered();
    void on_actionRunScript_triggered();

private slots:
    void on_pushButtonDisconnection_clicked();
    void on_pushButtonClose_clicked();

    void on_actionTeleportSlavesToMaster_triggered();

private:
    Ui::AccountForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    QString m_path;

    QMenu *menuScript;
    QMenu *menuGroupSettings;

    ConsoleForm *consoleForm;
    CharacterForm *characterForm;
    InventoryForm *inventoryForm;
    MapForm *mapForm;
    FloodForm *floodForm;
    FightForm *fightForm;
    SettingsForm *settingsForm;
    StatisticsForm *statisticsForm;

    QList<AccountForm*> m_accountFormChilds;
};

#endif // ACCOUNTFORM_H
