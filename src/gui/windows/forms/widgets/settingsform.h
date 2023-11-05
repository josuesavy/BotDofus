#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include <QMovie>
#include <QNetworkReply>
#include <QTableWidget>

#include "src/core/process/ProcessEngine.h"
#include "src/core/DataHandler.h"
#include "src/protocol/network/messages/AbstractMessage.h"

#define MAIN_SERVER_IP "dofus2-co-production.ankama-games.com"

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~SettingsForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface();

    void hasConnected();
    void hasDisconnected(QAbstractSocket::SocketError socketError);

private slots:
    void on_checkBoxAutoReconnect_stateChanged(int arg1);
    void on_checkBoPreventInactivityDisconnects_stateChanged(int arg1);
    void on_checkBoxAutoAcceptAchievement_stateChanged(int arg1);
    void on_pushButtonCheckAndApplyProxy_clicked();

    void on_groupBox_6_clicked(bool checked);

    void on_comboBoxStatus_currentIndexChanged(int index);

private:
    Ui::SettingsForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    QTcpSocket m_socket;
    ProxyInfos m_proxy;

    int currentIndexSelected;

    const BotData &getData() const;
};

#endif // SETTINGSFORM_H
