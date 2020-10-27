#ifndef STATISTICSFORM_H
#define STATISTICSFORM_H

#include <QWidget>

#include "src/Engines/Core/Process/ProcessEngine.h"
#include "src/Engines/Storage/DataHandler.h"
#include "src/Public.h"

namespace Ui {
class StatisticsForm;
}

class StatisticsForm : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~StatisticsForm();

    SocketIO *getSocket();
    QString getTime(uint timeStamp);
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface();

private:
    Ui::StatisticsForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;
};

#endif // STATISTICSFORM_H
