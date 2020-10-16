#include "configurationform.h"
#include "ui_configurationform.h"

ConfigurationForm::ConfigurationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigurationForm)
{
    ui->setupUi(this);
}

ConfigurationForm::~ConfigurationForm()
{
    delete ui;
}
