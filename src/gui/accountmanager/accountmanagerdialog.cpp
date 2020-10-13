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

    ui->tabWidget->addTab(loaderAccountForm, "Charger des comptes");
    ui->tabWidget->addTab(addAccountForm, "Ajouter des comptes");
    ui->tabWidget->addTab(characterCreatorForm, "Ajouter un personnage");
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
