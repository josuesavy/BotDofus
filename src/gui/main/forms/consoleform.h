#ifndef CONSOLEFORM_H
#define CONSOLEFORM_H

#include <QWidget>

#include "dialogs/smileysdialog.h"

#include "src/engines/core/process/ProcessEngine.h"
#include "src/engines/DataHandler.h"
#include "src/Public.h"

// Canaux Dofus
#define GLOBAL_COLOR "#E9E9E9"
#define TEAM_COLOR "#FF006C"
#define GUILD_COLOR "#975FFF"
#define ALLIANCE_COLOR "#FFAD42"
#define PARTY_COLOR "#00E4FF"
#define SALES_COLOR "#B3783E"
#define SEEK_COLOR "#E4A0D5"
#define NOOB_COLOR "#D3AA07"
#define ADMIN_COLOR "#FF00FF"
#define ADS_COLOR "#24a394"
#define ARENA_COLOR "#F16392"
#define PRIVATE_COLOR "#7EC3FF"
#define FIGHT_COLOR "#009900"
#define PROMOTION_COLOR "#eb684e"
#define COMMUNITY_COLOR "#9EC79D"

// SweatedBox
#define DEBUG_COLOR "#01b1da"
#define INFO_COLOR "#27984A"
#define WARN_COLOR "#ffa500"
#define ERROR_COLOR "#BC382A"
#define ACTION_COLOR "#276BAD"

//#define DEBUG_COLOR "#01b1da"
//#define INFO_COLOR "#009900"
//#define WARN_COLOR "#ffa500"
//#define ERROR_COLOR "#c10000"
//#define ACTION_COLOR "#1A429B"

namespace Ui {
class ConsoleForm;
}

class ConsoleForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConsoleForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~ConsoleForm();

    SocketIO *getSocket();
    QString getTime(uint timeStamp);
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface();

private slots:
    void on_lineEditConsole_returnPressed();

    void on_pushButtonSmiley_clicked();

    void on_pushButtonSend_clicked();

    void on_comboBoxCanal_currentIndexChanged(int index);

private:
    Ui::ConsoleForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;

    uint m_logMessageCount;
};

#endif // CONSOLEFORM_H
