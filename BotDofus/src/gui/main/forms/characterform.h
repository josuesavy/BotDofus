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
    void loadCharacterFaceUrl(QNetworkReply *reply);

private slots:
    void on_pushButtonAddVitality_clicked();
    void on_pushButtonAddWisdom_clicked();
    void on_pushButtonAddStrength_clicked();
    void on_pushButtonAddIntelligence_clicked();
    void on_pushButtonAddChance_clicked();
    void on_pushButtonAddAgility_clicked();

    void on_pushButtonResetCharacteristics_clicked();

private:
    Ui::CharacterForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;

    QNetworkAccessManager *managerFullSkin;
    QNetworkAccessManager *managerFaceSkin;
};

#endif // CHARACTERFORM_H
