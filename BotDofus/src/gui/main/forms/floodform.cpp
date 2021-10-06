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
        QModelIndex currentFloodIndex = ui->tableWidgetFlood->currentIndex();
        ui->tableWidgetFlood->setCurrentIndex(currentFloodIndex);
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {
        while(ui->tableWidgetFlood->rowCount() > 0)
            ui->tableWidgetFlood->removeRow(0);
    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        while(ui->tableWidgetFlood->rowCount() > 0)
            ui->tableWidgetFlood->removeRow(0);
    }
}

void FloodForm::on_pushButtonAddFlood_clicked()
{
    AddFloodMessageDialog addFloodMessageDialog;
    addFloodMessageDialog.setParent(this, Qt::Dialog);
    if(addFloodMessageDialog.exec() == QDialog::Accepted)
    {
        FloodMessage floodMessage;
        floodMessage.channel = (Channel)addFloodMessageDialog.getChannel();
        floodMessage.message = addFloodMessageDialog.getMessage();
        floodMessage.timer = addFloodMessageDialog.getInterval();
        floodMessage.someoneComingOnMap = addFloodMessageDialog.getSomeoneComingOnMap();
        floodMessage.someoneLeaveMap = addFloodMessageDialog.getSomeoneLeaveMap();
        floodMessage.startTimePlanning = addFloodMessageDialog.getStartTimePlanning();
        floodMessage.endTimePlanning = addFloodMessageDialog.getEndTimePlanning();

        m_engine->getFloodManager().addFloodChannel(m_sender, floodMessage);

        ui->tableWidgetFlood->insertRow(ui->tableWidgetFlood->rowCount());
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 0, new QTableWidgetItem(QString::number(floodMessage.channel)));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 1, new QTableWidgetItem(floodMessage.message));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 2, new QTableWidgetItem(floodMessage.timer.toString()));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 3, new QTableWidgetItem(QString("%1 - %2").arg(floodMessage.startTimePlanning.toString()).arg(floodMessage.endTimePlanning.toString())));
    }
}

void FloodForm::on_checkBoxEnableFlood_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        m_engine->getFloodManager().startFlood(m_sender);
    else if (arg1 == Qt::Unchecked)
        m_engine->getFloodManager().endFlood(m_sender);
}

void FloodForm::on_pushButtonDeleteFlood_clicked()
{
    if(ui->tableWidgetFlood->selectedItems().count() > 0)
    {
        foreach (const QModelIndex &indexModel, ui->tableWidgetFlood->selectionModel()->selectedIndexes())
        {
            m_engine->getFloodManager().removeFloodChannel(m_sender, m_engine->getData(m_sender).floodData.floodList.at(indexModel.row()));
        }
    }
    else
        QMessageBox::critical(this,"Error","Please select a flood in the list");
}

