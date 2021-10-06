#include "addfloodmessagedialog.h"
#include "ui_addfloodmessagedialog.h"

AddFloodMessageDialog::AddFloodMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFloodMessageDialog)
{
    ui->setupUi(this);

    if (!ui->radioButtonPublic->isChecked() && !ui->radioButtonPrivate->isChecked())
    {
        ui->groupBoxPublic->setEnabled(false);
        ui->groupBoxPrivate->setEnabled(false);
    }

    m_channel = ui->comboBoxChannel->currentIndex();
    m_message = ui->lineEditMessage->text();
    m_interval = ui->timeEditPublic->time();
    m_someoneComingOnMap = ui->checkBoxSomeoneComingMap->isChecked();
    m_someoneLeaveMap = ui->checkBoxSomeoneLeavesMap->isChecked();

    if(ui->checkBoxPlanning->isChecked())
    {
        m_startTimePlanning = ui->timeEditStartTimePlanning->time();
        m_endTimePlanning = ui->timeEditEndTimePlanning->time();
    }
    else
    {
        m_startTimePlanning = QTime();
        m_endTimePlanning = QTime();
    }
}

AddFloodMessageDialog::~AddFloodMessageDialog()
{
    delete ui;
}

QString AddFloodMessageDialog::getMessage()
{
    return m_message;
}

int AddFloodMessageDialog::getChannel()
{
    return m_channel;
}

QTime AddFloodMessageDialog::getInterval()
{
    return m_interval;
}

bool AddFloodMessageDialog::getSomeoneComingOnMap()
{
    return m_someoneComingOnMap;
}

bool AddFloodMessageDialog::getSomeoneLeaveMap()
{
    return m_someoneLeaveMap;
}

QTime AddFloodMessageDialog::getStartTimePlanning()
{
    return m_startTimePlanning;
}

QTime AddFloodMessageDialog::getEndTimePlanning()
{
    return m_endTimePlanning;
}

void AddFloodMessageDialog::on_lineEditMessage_textChanged(const QString &arg1)
{
    m_message = arg1;
}

void AddFloodMessageDialog::on_radioButtonPublic_clicked()
{
    ui->groupBoxPublic->setEnabled(true);
    ui->groupBoxPrivate->setEnabled(false);
}

void AddFloodMessageDialog::on_radioButtonPrivate_clicked()
{
    ui->groupBoxPrivate->setEnabled(true);
    ui->groupBoxPublic->setEnabled(false);
}

void AddFloodMessageDialog::on_checkBoxPlanning_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui->groupBoxPlanning->setEnabled(true);
        m_startTimePlanning = ui->timeEditStartTimePlanning->time();
        m_endTimePlanning = ui->timeEditEndTimePlanning->time();
    }
    else if (arg1 == Qt::Unchecked)
    {
        ui->groupBoxPlanning->setEnabled(false);
        m_startTimePlanning = QTime();
        m_endTimePlanning = QTime();
    }
}

void AddFloodMessageDialog::on_comboBoxCanal_currentIndexChanged(int index)
{
    m_channel = index;
}

void AddFloodMessageDialog::on_timeEditPublic_timeChanged(const QTime &time)
{
    m_interval = time;
}

void AddFloodMessageDialog::on_checkBoxSomeoneComingMap_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        m_someoneComingOnMap = true;
    else if (arg1 == Qt::Unchecked)
        m_someoneComingOnMap = false;
}


void AddFloodMessageDialog::on_checkBoxSomeoneLeavesMap_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        m_someoneLeaveMap = true;
    else if (arg1 == Qt::Unchecked)
        m_someoneLeaveMap = false;
}

void AddFloodMessageDialog::on_pushButtonAdd_clicked()
{
    if (ui->radioButtonPublic->isChecked() || ui->radioButtonPrivate->isChecked())
        accept();
}

void AddFloodMessageDialog::on_pushButtonCancel_clicked()
{
    reject();
}

