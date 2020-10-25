#ifndef ADDFLOODMESSAGEDIALOG_H
#define ADDFLOODMESSAGEDIALOG_H

#include <QDialog>

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
    int getCanal();

private slots:
    void on_radioButtonPublic_clicked();

    void on_radioButtonPrivate_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonCancel_clicked();

    void on_lineEditMessage_textChanged(const QString &arg1);

    void on_comboBoxCanal_currentIndexChanged(int index);

private:
    Ui::AddFloodMessageDialog *ui;

    QString m_message;
    int m_canal;

};

#endif // ADDFLOODMESSAGEDIALOG_H
