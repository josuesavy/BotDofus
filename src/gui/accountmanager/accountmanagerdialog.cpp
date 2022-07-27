#include "accountmanagerdialog.h"
#include "ui_accountmanagerdialog.h"

AccountManagerDialog::AccountManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountManagerDialog)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    loaderAccountForm = new LoaderAccountForm(ui->tabWidget);
    addAccountForm = new AddAccountForm(ui->tabWidget);
    characterCreatorForm = new CharacterCreatorForm(ui->tabWidget);

    ui->tabWidget->addTab(loaderAccountForm, "Load accounts");
    ui->tabWidget->addTab(addAccountForm, "Add accounts");
    ui->tabWidget->addTab(characterCreatorForm, "Add a character");
    //ui->tabWidget->addTab(new QWidget(),"Abonner des comptes");

    //ui->tabWidget->setTabEnabled(3, false);

    connect(loaderAccountForm, SIGNAL(loadAccount(const QList<ConnectionInfos>&)), this, SIGNAL(loadAccount(const QList<ConnectionInfos>&)));
    connect(addAccountForm, SIGNAL(updateListAccounts()), loaderAccountForm, SLOT(initialization()));
    connect(addAccountForm, SIGNAL(updateListAccounts()), characterCreatorForm, SLOT(initialization()));
    connect(loaderAccountForm, SIGNAL(updateListAccounts()), characterCreatorForm, SLOT(initialization()));
}

AccountManagerDialog::~AccountManagerDialog()
{
    delete loaderAccountForm;
    delete addAccountForm;
    delete characterCreatorForm;
    delete ui;
}

LoaderAccountForm *AccountManagerDialog::getLoaderAccountForm()
{
    return loaderAccountForm;
}

AddAccountForm *AccountManagerDialog::getAddAccountForm()
{
    return addAccountForm;
}

CharacterCreatorForm *AccountManagerDialog::getCharacterCreatorForm()
{
    return characterCreatorForm;
}

void AccountManagerDialog::closeAfterLoaded()
{
    if(ui->checkBoxCloseAfterLoaded->isChecked())
        close();
}

void AccountManagerDialog::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void AccountManagerDialog::on_buttonBox_accepted()
{
    accept();
}

void AccountManagerDialog::on_checkBoxCloseAfterLoaded_stateChanged(int arg1)
{
    switch (arg1)
    {
    case (int)Qt::Unchecked:
        // TODO: check in the database if the data exist and change value
        break;
    case (int)Qt::PartiallyChecked:
        break;
    case (int)Qt::Checked:
        break;
    }
}
