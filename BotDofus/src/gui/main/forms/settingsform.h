#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include <QMovie>
#include <QNetworkReply>

#include "src/Engines/Core/Process/ProcessEngine.h"
#include "src/Engines/Storage/DataHandler.h"

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
    void updateInterface(bool directCall = true);

    void hasConnected();
    void hasDisconnected();

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

    ProxyInfos m_proxy;

    int currentIndexSelected;

    const BotData &getData() const;
};

#endif // SETTINGSFORM_H
