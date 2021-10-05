#ifndef CHARACTERCREATORFORM_H
#define CHARACTERCREATORFORM_H

#include <QWidget>
#include <QColorDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QtSql/QtSql>

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/ProcessEngine.h"
#include "src/engines/io/d2o/D2OManager.h"

namespace Ui {
class CharacterCreatorForm;
}

class CharacterCreatorForm : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterCreatorForm(QWidget *parent = nullptr);
    ~CharacterCreatorForm();

    int generateRandomNumber(int min, int max);

public slots:
    void initialization();

private slots:
    void on_comboBoxBreed_currentIndexChanged(int index);
    void on_checkBoxRandomBreed_stateChanged(int arg1);

    void on_comboBoxGender_currentIndexChanged(int index);
    void on_checkBoxRandomGender_stateChanged(int arg1);

    void on_checkBoxRandomHead_stateChanged(int arg1);
    void on_checkBoxRandomColor_stateChanged(int arg1);

    void on_pushButtonSkin_clicked();
    void on_pushButtonHair_clicked();
    void on_pushButtonClothing_1_clicked();
    void on_pushButtonClothing_2_clicked();
    void on_pushButtonClothing_3_clicked();
    void on_pushButtonResetColor_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::CharacterCreatorForm *ui;

    int skinColor, hairColor, clothingColor1, clothingColor2, clothingColor3;
};

#endif // CHARACTERCREATORFORM_H
