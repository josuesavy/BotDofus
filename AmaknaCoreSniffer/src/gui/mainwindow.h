#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "consoledialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDisplay_console_triggered();

    void on_actionRun_Dofus_triggered();

private:
    Ui::MainWindow *ui;

    ConsoleDialog *m_consoleDialog;
};
#endif // MAINWINDOW_H
