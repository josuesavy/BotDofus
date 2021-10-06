#ifndef ADDFLOODMESSAGEDIALOG_H
#define ADDFLOODMESSAGEDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class AddFloodMessageDialog;
}

class AddFloodMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFloodMessageDialog(QWidget *parent = nullptr);
    ~AddFloodMessageDialog();

    QString getMessage();
    int getChannel();
    QTime getInterval();
    bool getSomeoneComingOnMap();
    bool getSomeoneLeaveMap();
    QTime getStartTimePlanning();
    QTime getEndTimePlanning();

private slots:
    void on_lineEditMessage_textChanged(const QString &arg1);

    void on_radioButtonPublic_clicked();
    void on_radioButtonPrivate_clicked();
    void on_checkBoxPlanning_stateChanged(int arg1);

    void on_comboBoxCanal_currentIndexChanged(int index);
    void on_timeEditPublic_timeChanged(const QTime &time);

    void on_checkBoxSomeoneComingMap_stateChanged(int arg1);
    void on_checkBoxSomeoneLeavesMap_stateChanged(int arg1);

    void on_pushButtonAdd_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::AddFloodMessageDialog *ui;

    QString m_message;
    int m_channel;
    QTime m_interval;
    bool m_someoneComingOnMap;
    bool m_someoneLeaveMap;
    QTime m_startTimePlanning;
    QTime m_endTimePlanning;
};

#endif // ADDFLOODMESSAGEDIALOG_H
