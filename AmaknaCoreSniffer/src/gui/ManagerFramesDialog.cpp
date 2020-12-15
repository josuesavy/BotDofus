#include "managerframesdialog.h"
#include "ui_managerframesdialog.h"

ManagerFramesDialog::ManagerFramesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerFramesDialog)
{
    ui->setupUi(this);
}

ManagerFramesDialog::~ManagerFramesDialog()
{
    delete ui;
}
