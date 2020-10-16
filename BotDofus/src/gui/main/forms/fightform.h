#ifndef FIGHTFORM_H
#define FIGHTFORM_H

#include <QWidget>
#include <QDialogButtonBox>
#include <QFormLayout>

#include "src/Engines/Core/Process/ProcessEngine.h"
#include "src/Engines/Storage/DataHandler.h"

namespace Ui {
class FightForm;
}

class FightForm : public QWidget
{
    Q_OBJECT

public:
    explicit FightForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~FightForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface(bool directCall = true);

private slots:
    void on_pushButtonMoveTopSpell_clicked();

    void on_pushButtonMoveDownSpell_clicked();

    void on_pushButtonAddSpell_clicked();

    void on_pushButtonDeleteSpell_clicked();

    void on_comboBoxPositionFight_currentIndexChanged(int index);

    void on_comboBoxCloseFight_currentIndexChanged(int index);

    void on_comboBoxSpectator_currentIndexChanged(int index);

    void on_comboBoxBehavior_currentIndexChanged(int index);

    void on_spinBoxRegenerationMin_valueChanged(int arg1);

    void on_spinBoxRegenerationMax_valueChanged(int arg1);

private:
    Ui::FightForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;
};

#endif // FIGHTFORM_H
