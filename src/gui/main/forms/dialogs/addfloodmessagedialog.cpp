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
}

AddFloodMessageDialog::~AddFloodMessageDialog()
{
    delete ui;
}

QString AddFloodMessageDialog::getMessage()
{
    return m_message;
}

int AddFloodMessageDialog::getCanal()
{
    return m_canal;
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

void AddFloodMessageDialog::on_pushButtonAdd_clicked()
{
    if (ui->radioButtonPublic->isChecked() || ui->radioButtonPrivate->isChecked())
        accept();
}

void AddFloodMessageDialog::on_pushButtonCancel_clicked()
{
    reject();
}

void AddFloodMessageDialog::on_lineEditMessage_textChanged(const QString &arg1)
{
    m_message = arg1;
}

void AddFloodMessageDialog::on_comboBoxCanal_currentIndexChanged(int index)
{
    m_canal = index;
}
