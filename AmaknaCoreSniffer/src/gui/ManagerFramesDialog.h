#ifndef MANAGERFRAMESDIALOG_H
#define MANAGERFRAMESDIALOG_H

#include <QDialog>

namespace Ui {
class ManagerFramesDialog;
}

class ManagerFramesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerFramesDialog(QWidget *parent = nullptr);
    ~ManagerFramesDialog();

private:
    Ui::ManagerFramesDialog *ui;
};

#endif // MANAGERFRAMESDIALOG_H
