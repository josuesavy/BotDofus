#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_consoleDialog = new ConsoleDialog(ui->mdiArea);
    ui->mdiArea->addSubWindow(m_consoleDialog, Qt::Dialog);
    m_consoleDialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDisplay_console_triggered()
{
    if (!m_consoleDialog->isVisible())
    {
        m_consoleDialog = new ConsoleDialog(ui->mdiArea);
        ui->mdiArea->addSubWindow(m_consoleDialog, Qt::Dialog);
        m_consoleDialog->show();
    }
}

void MainWindow::on_actionRun_Dofus_triggered()
{

}
