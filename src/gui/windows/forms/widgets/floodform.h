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

#include "src/core/process/ProcessEngine.h"
#include "src/core/DataHandler.h"
#include "src/gui/utils/boxes/addfloodmessagedialog.h"

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

private:
    Ui::FloodForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;
};

#endif // FLOODFORM_H
