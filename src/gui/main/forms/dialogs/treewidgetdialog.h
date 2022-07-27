#ifndef TREEWIDGETDIALOG_H
#define TREEWIDGETDIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class TreeWidgetDialog;
}

class TreeWidgetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TreeWidgetDialog(QWidget *parent = nullptr);
    ~TreeWidgetDialog();

    void addItem(QPair<double, QPair<QIcon, QString>> item);
    void addItems(QList<QPair<double, QPair<QIcon, QString>>> items);

    QPair<double, QPair<QIcon, QString> > getItemSelected();
    QTreeWidget *getTreeWidget();

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::TreeWidgetDialog *ui;
};

#endif // TREEWIDGETDIALOG_H
