#ifndef FLOODFORM_H
#define FLOODFORM_H

#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QTimeEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGridLayout>

#include "src/Engines/Core/Process/ProcessEngine.h"
#include "src/Engines/Storage/DataHandler.h"
#include "src/gui/main/forms/dialogs/addfloodmessagedialog.h"

namespace Ui {
class FloodForm;
}

class FloodForm : public QWidget
{
    Q_OBJECT

public:
    explicit FloodForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~FloodForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface();

private slots:
    void on_pushButtonAddFlood_clicked();

    void on_checkBoxEnableFlood_stateChanged(int arg1);

private:
    Ui::FloodForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;
};

#endif // FLOODFORM_H
