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
    AddFloodMessageDialog addFloodMessage;
    addFloodMessage.setParent(this, Qt::Dialog);
    if(addFloodMessage.exec() == QDialog::Accepted)
    {

    }
}
