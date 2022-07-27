#ifndef CHARACTERFORM_H
#define CHARACTERFORM_H

#include <QWidget>

#include <QNetworkReply>

#include "src/engines/utils/entitylook/EntityLookParser.h"
#include "src/engines/core/process/ProcessEngine.h"
#include "src/engines/DataHandler.h"

namespace Ui {
class CharacterForm;
}

class CharacterForm : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~CharacterForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface();
    void loadCharacterFullUrl(QNetworkReply *reply);

private slots:
    void on_pushButtonAddVitality_clicked();
    void on_pushButtonAddWisdom_clicked();
    void on_pushButtonAddStrength_clicked();
    void on_pushButtonAddIntelligence_clicked();
    void on_pushButtonAddChance_clicked();
    void on_pushButtonAddAgility_clicked();

    void on_pushButtonResetCharacteristics_clicked();

    void on_checkBoxShowAllJobs_stateChanged(int arg1);

private:
    Ui::CharacterForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    void displayJobs(bool all);
    const BotData &getData() const;

    QNetworkAccessManager *managerFullSkin;
};

#endif // CHARACTERFORM_H
