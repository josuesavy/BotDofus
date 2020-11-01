#include "floodform.h"
#include "ui_floodform.h"

FloodForm::FloodForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloodForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    ui->tableWidgetFlood->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

FloodForm::~FloodForm()
{
    delete ui;
}

SocketIO *FloodForm::getSocket()
{
    return m_sender;
}

ConnectionInfos FloodForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &FloodForm::getData() const
{
    return m_engine->getData(m_sender);
}

void FloodForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }
}

void FloodForm::on_pushButtonAddFlood_clicked()
{
    AddFloodMessageDialog addFloodMessageDialog;
    addFloodMessageDialog.setParent(this, Qt::Dialog);
    if(addFloodMessageDialog.exec() == QDialog::Accepted)
    {
        FloodMessage floodMessage;
        floodMessage.channel = (Channel)addFloodMessageDialog.getCanal();
        floodMessage.message = addFloodMessageDialog.getMessage();
        floodMessage.timer = addFloodMessageDialog.getInterval();

        m_engine->getFloodModule().addFloodChannel(m_sender, floodMessage);

        ui->tableWidgetFlood->insertRow(ui->tableWidgetFlood->rowCount());
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 0, new QTableWidgetItem(QString::number(floodMessage.channel)));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 1, new QTableWidgetItem(floodMessage.message));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 2, new QTableWidgetItem(floodMessage.timer.toString()));
    }
}

void FloodForm::on_checkBoxEnableFlood_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        m_engine->getFloodModule().initFlood(m_sender, getData().floodData.floodList);
    else if (arg1 == Qt::Unchecked)
        m_engine->getFloodModule().endFlood(m_sender);
}
