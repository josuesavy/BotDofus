#include "charactercreatorform.h"
#include "ui_charactercreatorform.h"

CharacterCreatorForm::CharacterCreatorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterCreatorForm)
{
    ui->setupUi(this);

    initialization();

    // Alimentation de la liste des serveurs
    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SERVERS))
    {
        QSharedPointer<ServerData> serverData = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, index));
        if(serverData->getLanguage() == "fr")
        {
            QSharedPointer<ServerGameTypeData> serverGameTypeData = qSharedPointerCast<ServerGameTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERGAMETYPES, serverData->getGameTypeId()));
            if(serverGameTypeData->getSelectableByPlayer())
                ui->comboBoxServer->addItem(serverData->getName(), serverData->getId());
        }
    }

    // Alimentation de la liste des races
    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::BREEDS))
    {
        QSharedPointer<BreedData> breedData = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, index));
        ui->comboBoxBreed->addItem(breedData->getShortName(), breedData->getId());
    }

    ui->comboBoxBreed->setCurrentIndex(0);

    if(ui->listWidgetAccounts->count() > 0)
        ui->groupBoxCreatePlayer->setEnabled(true);
}

CharacterCreatorForm::~CharacterCreatorForm()
{
    delete ui;
}

void CharacterCreatorForm::initialization()
{
    ui->listWidgetAccounts->clear();

    QSqlQuery query;
    query.prepare("SELECT login FROM accounts");

    if(query.exec())
    {
        while(query.next())
            ui->listWidgetAccounts->addItem(query.value(0).toString());
    }
}

int CharacterCreatorForm::generateRandomNumber(int min, int max)
{
    return (qrand() % (max - min + 1)) + min;
}

void CharacterCreatorForm::on_comboBoxBreed_currentIndexChanged(int index)
{
    ui->comboBoxHead->clear();

    // Alimentation de la liste des têtes
    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::HEADS))
    {
        QSharedPointer<HeadData> headData = qSharedPointerCast<HeadData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::HEADS, index));
        if(headData->getBreed() == ui->comboBoxBreed->currentIndex()+1 && headData->getGender() == ui->comboBoxGender->currentIndex())
            ui->comboBoxHead->addItem(QIcon(D2PManagerSingleton::get()->getPathFolder()+ QString("/gfx/cosmetics/%1.png").arg(headData->getAssetId())), headData->getLabel(), headData->getId());
    }


    // Alimentation des couleurs
    QList<uint> colors;
    if(ui->comboBoxGender->currentIndex() == 0)
        colors = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, index+1))->getMaleColors();

    else
        colors = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, index+1))->getFemaleColors();

    for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
    {
        int color = colors.at(i);

        int red = color / 65536;
        int green = (color - red*65536)/256;
        int blue = color - red*65536  - green*256;

        ui->gridLayout_3->itemAt(i)->widget()->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_checkBoxRandomBreed_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        ui->comboBoxBreed->setEnabled(false);
    else
        ui->comboBoxBreed->setEnabled(true);
}

void CharacterCreatorForm::on_comboBoxGender_currentIndexChanged(int index)
{
    ui->comboBoxHead->clear();

    // Alimentation de la liste des têtes
    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::HEADS))
    {
        QSharedPointer<HeadData> headData = qSharedPointerCast<HeadData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::HEADS, index));
        if(headData->getBreed() == ui->comboBoxBreed->currentIndex()+1 && headData->getGender() == ui->comboBoxGender->currentIndex())
            ui->comboBoxHead->addItem(QIcon(D2PManagerSingleton::get()->getPathFolder()+ QString("/gfx/cosmetics/%1.png").arg(headData->getAssetId())), headData->getLabel(), headData->getId());
    }


    // Alimentation des couleurs
    QList<uint> colors;
    if(index == 0)
        colors = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, ui->comboBoxBreed->currentIndex()+1))->getMaleColors();

    else
        colors = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, ui->comboBoxBreed->currentIndex()+1))->getFemaleColors();

    for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
    {
        int color = colors.at(i);

        int red = color / 65536;
        int green = (color - red*65536)/256;
        int blue = color - red*65536  - green*256;

        ui->gridLayout_3->itemAt(i)->widget()->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_checkBoxRandomGender_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        ui->comboBoxGender->setEnabled(false);
    else
        ui->comboBoxGender->setEnabled(true);
}

void CharacterCreatorForm::on_checkBoxRandomHead_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        ui->comboBoxHead->setEnabled(false);
    else
        ui->comboBoxHead->setEnabled(true);
}

void CharacterCreatorForm::on_checkBoxRandomColor_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
            ui->gridLayout_3->itemAt(i)->widget()->setEnabled(false);

    else
        for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
            ui->gridLayout_3->itemAt(i)->widget()->setEnabled(true);
}

void CharacterCreatorForm::on_pushButtonSkin_clicked()
{
    int red = ui->pushButtonSkin->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
    int green = ui->pushButtonSkin->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
    int blue = ui->pushButtonSkin->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

    QColor color = QColorDialog::getColor(QColor(red,green,blue), this);
    if(color.isValid())
    {
        skinColor = color.red()*65536 +  color.green()*256   +  color.blue();
        ui->pushButtonSkin->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    else
    {
        skinColor = red*65536 +  green*256   +  blue;
        ui->pushButtonSkin->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }

    // RGB to INT
    // val = red*65536 +  green*256   +  blue;

    // INT to RGB
    // red = val / 65536;
    // green = (val - red*65536)/256;
    // blue = val - red*65536  - green*256;
}

void CharacterCreatorForm::on_pushButtonHair_clicked()
{
    int red = ui->pushButtonHair->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
    int green = ui->pushButtonHair->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
    int blue = ui->pushButtonHair->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

    QColor color = QColorDialog::getColor(QColor(red,green,blue), this);
    if(color.isValid())
    {
        hairColor = color.red()*65536 +  color.green()*256   +  color.blue();
        ui->pushButtonHair->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    else
    {
        hairColor = red*65536 +  green*256   +  blue;
        ui->pushButtonHair->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_pushButtonClothing_1_clicked()
{
    int red = ui->pushButtonClothing_1->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
    int green = ui->pushButtonClothing_1->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
    int blue = ui->pushButtonClothing_1->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

    QColor color = QColorDialog::getColor(QColor(red,green,blue), this);
    if(color.isValid())
    {
        clothingColor1 = color.red()*65536 +  color.green()*256   +  color.blue();
        ui->pushButtonClothing_1->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    else
    {
        clothingColor1 = red*65536 +  green*256   +  blue;
        ui->pushButtonClothing_1->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_pushButtonClothing_2_clicked()
{
    int red = ui->pushButtonClothing_2->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
    int green = ui->pushButtonClothing_2->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
    int blue = ui->pushButtonClothing_2->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

    QColor color = QColorDialog::getColor(QColor(red,green,blue), this);
    if(color.isValid())
    {
        clothingColor2 = color.red()*65536 +  color.green()*256   +  color.blue();
        ui->pushButtonClothing_2->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    else
    {
        clothingColor2 = red*65536 +  green*256   +  blue;
        ui->pushButtonClothing_2->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_pushButtonClothing_3_clicked()
{
    int red = ui->pushButtonClothing_3->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
    int green = ui->pushButtonClothing_3->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
    int blue = ui->pushButtonClothing_3->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

    QColor color = QColorDialog::getColor(QColor(red,green,blue), this);
    if(color.isValid())
    {
        clothingColor3 = color.red()*65536 +  color.green()*256   +  color.blue();
        ui->pushButtonClothing_3->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    else
    {
        clothingColor3 = red*65536 +  green*256   +  blue;
        ui->pushButtonClothing_3->setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue));
    }
}

void CharacterCreatorForm::on_pushButtonResetColor_clicked()
{
    if(!ui->checkBoxRandomColor->isChecked())
        for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
            ui->gridLayout_3->itemAt(i)->widget()->setStyleSheet("");
}

void CharacterCreatorForm::on_pushButtonSave_clicked()
{
    if(!ui->listWidgetAccounts->selectedItems().isEmpty() && ui->groupBoxCreatePlayer->isChecked())
    {
        int breedId, genderId, headerId;

        if(ui->checkBoxRandomBreed->isChecked())
            breedId = generateRandomNumber(1, 18);
        else
            breedId = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::BREEDS).at(ui->comboBoxBreed->currentIndex());

        if(ui->checkBoxRandomGender->isChecked())
            genderId = generateRandomNumber(0, 1);
        else
            genderId = ui->comboBoxGender->currentIndex();

        QList<int> headerIdList;
        if(ui->checkBoxRandomHead->isChecked())
        {
            foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::HEADS))
            {
                QSharedPointer<HeadData> headData = qSharedPointerCast<HeadData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::HEADS, index));
                if(headData->getBreed() == breedId && headData->getGender() == genderId)
                    headerIdList << headData->getId();
            }

            headerId = generateRandomNumber(headerIdList.first(), headerIdList.last());
        }
        else
            headerId = ui->comboBoxHead->currentData().toInt();

        QList<QString> colors;
        if(ui->checkBoxRandomColor->isChecked())
        {
            for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
                colors.push_back(QString::number(generateRandomNumber(0, 16777215)));
        }
        else
        {
            for(int i = 0; i < ui->gridLayout_3->count()-1; i++)
            {
                int red = ui->gridLayout_3->itemAt(i)->widget()->styleSheet().split("(").at(1).split(")").at(0).split(",").at(0).toInt();
                int green = ui->gridLayout_3->itemAt(i)->widget()->styleSheet().split("(").at(1).split(")").at(0).split(",").at(1).toInt();
                int blue = ui->gridLayout_3->itemAt(i)->widget()->styleSheet().split("(").at(1).split(")").at(0).split(",").at(2).toInt();

                colors.push_back(QString::number(red*65536 +  green*256   +  blue));
            }
        }

        QSqlQuery query;
        query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
        query.bindValue(":login", ui->listWidgetAccounts->currentItem()->text());

        if (query.exec())
        {
            if (query.next())
            {
                int idAccount = query.value(0).toInt();

                query.prepare("SELECT * FROM creation WHERE idaccounts = (:idaccounts)");
                query.bindValue(":idaccounts", idAccount);

                if (query.exec())
                {
                    if (query.next())
                    {
                        query.prepare("UPDATE creation SET name=:name, server=:server, breed=:breed, sex=:sex, head=:head, colors=:colors, didactiel=:didactiel WHERE idaccounts=:idaccounts");
                        query.bindValue(":name", ui->lineEditName->text());
                        query.bindValue(":server", ui->comboBoxServer->currentData().toInt());
                        query.bindValue(":breed", breedId);
                        query.bindValue(":sex", genderId);
                        query.bindValue(":head", headerId);
                        query.bindValue(":colors", colors.join("|"));
                        query.bindValue(":didactiel", !ui->checkBoxSkipDidactiel->isChecked());
                        query.bindValue(":idaccounts", idAccount);

                        if(query.exec())
                            QMessageBox::information(this,"Sauvegarde","La demande a été modifié. Elle prendra effet lors de la prochaine connexion de ce compte.");
                        else
                            QMessageBox::critical(this,"Sauvegarde","Oops, une erreur s'est produite. Veuillez réessayez ultérieurement.");
                    }

                    else
                    {
                        query.prepare("INSERT INTO creation (name,server,breed,sex,head,colors,didactiel,idaccounts) VALUES(:name,:server,:breed,:sex,:head,:colors,:didactiel,:idaccounts)");
                        query.bindValue(":name", ui->lineEditName->text());
                        query.bindValue(":server", ui->comboBoxServer->currentData().toInt());
                        query.bindValue(":breed", breedId);
                        query.bindValue(":sex", genderId);
                        query.bindValue(":head", headerId);
                        query.bindValue(":colors", colors.join("|"));
                        query.bindValue(":didactiel", !ui->checkBoxSkipDidactiel->isChecked());
                        query.bindValue(":idaccounts", idAccount);

                        if(query.exec())
                            QMessageBox::information(this,"Sauvegarde","La demande a été ajouté. Elle prendra effet lors de la prochaine connexion de ce compte.");
                        else
                            QMessageBox::critical(this,"Sauvegarde","Oops, une erreur s'est produite. Veuillez réessayez ultérieurement.");
                    }
                }
            }
        }
    }

    else if(!ui->listWidgetAccounts->selectedItems().isEmpty() && !ui->groupBoxCreatePlayer->isChecked())
    {
        QSqlQuery query;
        query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
        query.bindValue(":login", ui->listWidgetAccounts->currentItem()->text());

        if (query.exec())
        {
            if (query.next())
            {
                int idAccount = query.value(0).toInt();

                query.prepare("SELECT idaccounts FROM creation WHERE idaccounts = (:idaccounts)");
                query.bindValue(":idaccounts", idAccount);

                if (query.exec())
                {
                    if (query.next())
                    {
                        query.prepare("DELETE FROM creation WHERE idaccounts=:idaccounts");
                        query.bindValue(":idaccounts", idAccount);

                        if(query.exec())
                            QMessageBox::information(this,"Supression","La demande a été supprimé.");
                        else
                            QMessageBox::critical(this,"Supression","Une erreur s'est produite... Veuillez réessayer ultérieurement.");
                    }

                    else
                        QMessageBox::critical(this,"Erreur","Impossible de supprimer la demande. Aucune demande n'a été faite sur ce compte.");
                }

                else
                    QMessageBox::critical(this,"Sauvegarde","Oops, une erreur s'est produite. Veuillez réessayez ultérieurement.");
            }
        }
    }

    else
        QMessageBox::critical(this,"Erreur","Veuillez sélectionné un compte dans la liste");
}
