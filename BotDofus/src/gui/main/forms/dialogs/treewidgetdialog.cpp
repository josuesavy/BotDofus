#include "treewidgetdialog.h"
#include "ui_treewidgetdialog.h"

TreeWidgetDialog::TreeWidgetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeWidgetDialog)
{
    ui->setupUi(this);
}

TreeWidgetDialog::~TreeWidgetDialog()
{
    delete ui;
}

void TreeWidgetDialog::addItem(QPair<double, QPair<QIcon, QString> > item)
{
    QTreeWidgetItem* treeWidgetItem = new QTreeWidgetItem(ui->treeWidget);
    treeWidgetItem->setIcon(0, item.second.first);
    treeWidgetItem->setText(0, item.second.second);
    treeWidgetItem->setData(0, Qt::UserRole, item.first);

    ui->treeWidget->addTopLevelItem(treeWidgetItem);
}

void TreeWidgetDialog::addItems(QList<QPair<double, QPair<QIcon, QString> > > items)
{
    QPair<double, QPair<QIcon, QString>> pair;
    foreach (pair, items)
    {
        QTreeWidgetItem* treeWidgetItem = new QTreeWidgetItem(ui->treeWidget);
        treeWidgetItem->setIcon(0, pair.second.first);
        treeWidgetItem->setText(0, pair.second.second);
        treeWidgetItem->setData(0, Qt::UserRole, pair.first);

        ui->treeWidget->addTopLevelItem(treeWidgetItem);
    }
}

QPair<double, QPair<QIcon, QString> > TreeWidgetDialog::getItemSelected()
{
    QPair<double, QPair<QIcon, QString>> pair;

    if (ui->treeWidget->selectedItems().count())
    {
        pair.first = ui->treeWidget->selectedItems().first()->data(0, Qt::UserRole).toDouble();
        pair.second.first = ui->treeWidget->selectedItems().first()->icon(0);
        pair.second.second = ui->treeWidget->selectedItems().first()->text(0);
    }

    return pair;
}

QTreeWidget *TreeWidgetDialog::getTreeWidget()
{
    return ui->treeWidget;
}

void TreeWidgetDialog::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    accept();
}
