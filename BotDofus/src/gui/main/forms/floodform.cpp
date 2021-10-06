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
    ui->checkBoxEnableFlood->setEnabled(false);
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
        floodMessage.channel = (Channel)addFloodMessageDialog.getChannel();
        floodMessage.message = addFloodMessageDialog.getMessage();
        floodMessage.timer = addFloodMessageDialog.getInterval();
        floodMessage.someoneComingOnMap = addFloodMessageDialog.getSomeoneComingOnMap();
        floodMessage.someoneLeaveMap = addFloodMessageDialog.getSomeoneLeaveMap();
        floodMessage.startTimePlanning = addFloodMessageDialog.getStartTimePlanning();
        floodMessage.endTimePlanning = addFloodMessageDialog.getEndTimePlanning();

        m_engine->getFloodManager().addFloodChannel(m_sender, floodMessage);

        QString intervalString;
        if (!floodMessage.someoneComingOnMap && !floodMessage.someoneLeaveMap)
            intervalString = floodMessage.timer.toString();
        else
        {
            if (floodMessage.someoneComingOnMap)
                intervalString += "Coming";

            if (floodMessage.someoneLeaveMap)
            {
                if (floodMessage.someoneComingOnMap)
                    intervalString += " - Leave";
                else
                    intervalString += "Leave";
            }
        }

        ui->tableWidgetFlood->insertRow(ui->tableWidgetFlood->rowCount());
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 0, new QTableWidgetItem(QString::number(floodMessage.channel)));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 1, new QTableWidgetItem(floodMessage.message));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 2, new QTableWidgetItem(intervalString));
        ui->tableWidgetFlood->setItem(ui->tableWidgetFlood->rowCount()-1, 3, new QTableWidgetItem(QString("%1 - %2").arg(floodMessage.startTimePlanning.toString()).arg(floodMessage.endTimePlanning.toString())));

        ui->checkBoxEnableFlood->setEnabled(true);
    }
}

void FloodForm::on_checkBoxEnableFlood_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked && ui->tableWidgetFlood->rowCount() > 0 && !m_engine->getData(m_sender).floodData.floodList.isEmpty())
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
            if (!m_engine->getData(m_sender).floodData.floodList.isEmpty())
            {
                m_engine->getFloodManager().removeFloodChannel(m_sender, m_engine->getData(m_sender).floodData.floodList.at(indexModel.row()));
                ui->tableWidgetFlood->removeRow(indexModel.row());
            }
        }

        if (ui->tableWidgetFlood->rowCount() <= 0)
        {
            ui->checkBoxEnableFlood->setChecked(false);
            ui->checkBoxEnableFlood->setEnabled(false);
        }
    }
    else
        QMessageBox::critical(this,"Error","Please select a flood in the list");
}

