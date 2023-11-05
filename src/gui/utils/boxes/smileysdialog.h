#ifndef SMILEYSDIALOG_H
#define SMILEYSDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QDebug>
#include <QString>


#include "src/core/DataHandler.h"
#include "src/gamedata/d2o/D2OManager.h"

namespace Ui {
class SmileysDialog;
}

class SmileysDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SmileysDialog(QWidget *parent = nullptr);
    ~SmileysDialog();

    void setSmileysHappy(QList<QString> smileys);
    void setSmileysSad(QList<QString> smileys);
    void setSmileysOther(QList<QString> smileys);

    QString smiley;

private slots:
    void on_listWidgetHappy_itemClicked(QListWidgetItem *item);

    void on_listWidgetSad_itemClicked(QListWidgetItem *item);

    void on_listWidgetOther_itemClicked(QListWidgetItem *item);

private:
    Ui::SmileysDialog *ui;

    void order(QList<QString> &list);
};

#endif // SMILEYSDIALOG_H
