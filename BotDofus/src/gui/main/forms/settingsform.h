#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include <QMovie>
#include <QNetworkReply>

#include "src/engines/core/process/ProcessEngine.h"
#include "src/engines/DataHandler.h"

#define MAIN_SERVER_IP_1 "34.252.21.81"
#define MAIN_SERVER_IP_2 "52.17.231.202"
#define MAIN_SERVER_IP_3 "63.34.214.78"

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

    QString processRandomIp();
    const BotData &getData() const;
};

#endif // SETTINGSFORM_H
