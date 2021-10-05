#include "smileysdialog.h"
#include "ui_smileysdialog.h"

SmileysDialog::SmileysDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmileysDialog)
{
    ui->setupUi(this);

    // On ne garde que le button fermer sur la fenêtre
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->tabWidget->setCurrentIndex(0);
}

SmileysDialog::~SmileysDialog()
{
    delete ui;
}

void SmileysDialog::setSmileysHappy(QList<QString> smileys)
{
    order(smileys);

    foreach(QString s, smileys)
        ui->listWidgetHappy->addItem(new QListWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(s.split('|').at(0))), s.split('|').at(1)));
}

void SmileysDialog::setSmileysSad(QList<QString> smileys)
{
    order(smileys);

    foreach(QString s, smileys)
        ui->listWidgetSad->addItem(new QListWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(s.split('|').at(0))), s.split('|').at(1)));
}

void SmileysDialog::setSmileysOther(QList<QString> smileys)
{
    order(smileys);

    foreach(QString s, smileys)
        ui->listWidgetOther->addItem(new QListWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(s.split('|').at(0))), s.split('|').at(1)));
}

void SmileysDialog::on_listWidgetHappy_itemClicked(QListWidgetItem *item)
{
    smiley = item->text();
    accept();
}

void SmileysDialog::on_listWidgetSad_itemClicked(QListWidgetItem *item)
{
    smiley = item->text();
    accept();
}

void SmileysDialog::on_listWidgetOther_itemClicked(QListWidgetItem *item)
{
    smiley = item->text();
    accept();
}

void SmileysDialog::order(QList<QString> &list)
{
    int max;
    int size = list.size();
    while(size > 0)
    {
        max = 0;
        for(int i = 1; i < size; i++)
        {
            if(list.at(i).split('|').at(2).toInt() > list.at(max).split('|').at(2).toInt())
                max=i;
        }
        list.swapItemsAt(max, size-1);
        size--;
    }
}
