#include "characterform.h"
#include "ui_characterform.h"

CharacterForm::CharacterForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    managerFaceSkin = new QNetworkAccessManager(this);
    managerFullSkin = new QNetworkAccessManager(this);

    QObject::connect(managerFaceSkin, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadCharacterFaceUrl(QNetworkReply*)));
    QObject::connect(managerFullSkin, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadCharacterFullUrl(QNetworkReply*)));

    ui->tableWidgetSpells->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidgetJobs->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

CharacterForm::~CharacterForm()
{
    delete ui;
}

SocketIO *CharacterForm::getSocket()
{
    return m_sender;
}

ConnectionInfos CharacterForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &CharacterForm::getData() const
{
    return m_engine->getData(m_sender);
}

void CharacterForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        // Display character's name
        ui->labelName->setText(QString("<b>%1</b>").arg(infos.mapData.playersOnMap[infos.mapData.botId].name));


        // Display character
        if(infos.mapData.playersOnMap[infos.mapData.botId].name == infos.connectionData.connectionInfos.character)
        {
            QUrl characterFullUrl(EntityLookParser::getUrl(infos.mapData.playersOnMap[infos.mapData.botId].look, EntityRendererType::FULL, EntityRendererOrientation::DIAGONAL_RIGHT));
            QUrl characterFaceUrl(EntityLookParser::getUrl(infos.mapData.playersOnMap[infos.mapData.botId].look, EntityRendererType::FACE, EntityRendererOrientation::DIAGONAL_RIGHT));

//            qDebug() << characterFullUrl;
//            qDebug() << characterFaceUrl;

            managerFaceSkin->get(QNetworkRequest(characterFaceUrl));
            managerFullSkin->get(QNetworkRequest(characterFullUrl));
        }


        // Display character's breed and level
        if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, (int)infos.playerData.breed));
            ui->labelDescription->setText(QString("%1, Level %2").arg(breed->getShortName()).arg(infos.mapData.playersOnMap[infos.mapData.botId].level));
        }

        else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
        {
            QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, (int)infos.playerData.breed));
            ui->labelDescription->setText(QString("%1, Level %2").arg(breed->getShortName()).arg(infos.fightData.fighters[infos.fightData.botFightData.botId].level));
        }


        // Display character's characteristics
        ui->labelAP->setText(QString::number(infos.playerData.stats[(uint)StatIds::ACTION_POINTS].base +
                                             infos.playerData.stats[(uint)StatIds::ACTION_POINTS].alignGiftBonus +
                                             infos.playerData.stats[(uint)StatIds::ACTION_POINTS].contextModif +
                                             infos.playerData.stats[(uint)StatIds::ACTION_POINTS].objectsAndMountBonus +
                                             infos.playerData.stats[(uint)StatIds::ACTION_POINTS].additional));
        ui->labelMP->setText(QString::number(infos.playerData.stats[(uint)StatIds::MOVEMENT_POINTS].base +
                                             infos.playerData.stats[(uint)StatIds::MOVEMENT_POINTS].alignGiftBonus +
                                             infos.playerData.stats[(uint)StatIds::MOVEMENT_POINTS].contextModif +
                                             infos.playerData.stats[(uint)StatIds::MOVEMENT_POINTS].objectsAndMountBonus +
                                             infos.playerData.stats[(uint)StatIds::MOVEMENT_POINTS].additional));
        if (m_engine->getStatsManager().getMaxHealthPoints(m_sender) != 0)
        {
            ui->labelInitiative->setText(QString("%1/%2")
                                         .arg((infos.playerData.stats[(uint)StatIds::INITIATIVE].base +infos.playerData.stats[(uint)StatIds::INITIATIVE].alignGiftBonus +
                                         infos.playerData.stats[(uint)StatIds::INITIATIVE].contextModif + infos.playerData.stats[(uint)StatIds::INITIATIVE].objectsAndMountBonus +
                    infos.playerData.stats[(uint)StatIds::INITIATIVE].additional)*m_engine->getStatsManager().getHealthPoints(m_sender) / m_engine->getStatsManager().getMaxHealthPoints(m_sender))
                    .arg(infos.playerData.stats[(uint)StatIds::INITIATIVE].base + infos.playerData.stats[(uint)StatIds::INITIATIVE].alignGiftBonus +
                    infos.playerData.stats[(uint)StatIds::INITIATIVE].contextModif + infos.playerData.stats[(uint)StatIds::INITIATIVE].objectsAndMountBonus +
                    infos.playerData.stats[(uint)StatIds::INITIATIVE].additional));
        }
        ui->labelProspecting->setText(QString::number(infos.playerData.stats[(uint)StatIds::MAGIC_FIND].base +
                                                      infos.playerData.stats[(uint)StatIds::MAGIC_FIND].alignGiftBonus +
                                                      infos.playerData.stats[(uint)StatIds::MAGIC_FIND].contextModif +
                                                      infos.playerData.stats[(uint)StatIds::MAGIC_FIND].objectsAndMountBonus +
                                                      infos.playerData.stats[(uint)StatIds::MAGIC_FIND].additional));
        ui->labelRange->setText(QString::number(infos.playerData.stats[(uint)StatIds::RANGE].base +
                                                infos.playerData.stats[(uint)StatIds::RANGE].alignGiftBonus +
                                                infos.playerData.stats[(uint)StatIds::RANGE].contextModif +
                                                infos.playerData.stats[(uint)StatIds::RANGE].objectsAndMountBonus +
                                                infos.playerData.stats[(uint)StatIds::RANGE].additional));
        ui->labelSummons->setText(QString::number(infos.playerData.stats[(uint)StatIds::MAX_SUMMONED_CREATURES_BOOST].base +
                                                  infos.playerData.stats[(uint)StatIds::MAX_SUMMONED_CREATURES_BOOST].alignGiftBonus +
                                                  infos.playerData.stats[(uint)StatIds::MAX_SUMMONED_CREATURES_BOOST].contextModif +
                                                  infos.playerData.stats[(uint)StatIds::MAX_SUMMONED_CREATURES_BOOST].objectsAndMountBonus +
                                                  infos.playerData.stats[(uint)StatIds::MAX_SUMMONED_CREATURES_BOOST].additional));
        ui->labelVitality->setText(QString::number(infos.playerData.stats[(uint)StatIds::VITALITY].base +
                                                   infos.playerData.stats[(uint)StatIds::VITALITY].alignGiftBonus +
                                                   infos.playerData.stats[(uint)StatIds::VITALITY].contextModif +
                                                   infos.playerData.stats[(uint)StatIds::VITALITY].objectsAndMountBonus +
                                                   infos.playerData.stats[(uint)StatIds::VITALITY].additional));
        ui->labelWisdom->setText(QString::number(infos.playerData.stats[(uint)StatIds::WISDOM].base +
                                                 infos.playerData.stats[(uint)StatIds::WISDOM].alignGiftBonus +
                                                 infos.playerData.stats[(uint)StatIds::WISDOM].contextModif +
                                                 infos.playerData.stats[(uint)StatIds::WISDOM].objectsAndMountBonus +
                                                 infos.playerData.stats[(uint)StatIds::WISDOM].additional));
        ui->labelStrength->setText(QString::number(infos.playerData.stats[(uint)StatIds::STRENGTH].base +
                                                   infos.playerData.stats[(uint)StatIds::STRENGTH].alignGiftBonus +
                                                   infos.playerData.stats[(uint)StatIds::STRENGTH].contextModif +
                                                   infos.playerData.stats[(uint)StatIds::STRENGTH].objectsAndMountBonus +
                                                   infos.playerData.stats[(uint)StatIds::STRENGTH].additional));
        ui->labelIntelligence->setText(QString::number(infos.playerData.stats[(uint)StatIds::INTELLIGENCE].base +
                                                       infos.playerData.stats[(uint)StatIds::INTELLIGENCE].alignGiftBonus +
                                                       infos.playerData.stats[(uint)StatIds::INTELLIGENCE].contextModif +
                                                       infos.playerData.stats[(uint)StatIds::INTELLIGENCE].objectsAndMountBonus +
                                                       infos.playerData.stats[(uint)StatIds::INTELLIGENCE].additional));
        ui->labelChance->setText(QString::number(infos.playerData.stats[(uint)StatIds::CHANCE].base +
                                                 infos.playerData.stats[(uint)StatIds::CHANCE].alignGiftBonus +
                                                 infos.playerData.stats[(uint)StatIds::CHANCE].contextModif +
                                                 infos.playerData.stats[(uint)StatIds::CHANCE].objectsAndMountBonus +
                                                 infos.playerData.stats[(uint)StatIds::CHANCE].additional));
        ui->labelAgility->setText(QString::number(infos.playerData.stats[(uint)StatIds::AGILITY].base +
                                                  infos.playerData.stats[(uint)StatIds::AGILITY].alignGiftBonus +
                                                  infos.playerData.stats[(uint)StatIds::AGILITY].contextModif +
                                                  infos.playerData.stats[(uint)StatIds::AGILITY].objectsAndMountBonus +
                                                  infos.playerData.stats[(uint)StatIds::AGILITY].additional));
        ui->labelCapitalPoints->setText(QString("<b>%1</b>").arg(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base));


        // Automatic booster
        if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0)
        {
            // Enable buttons stats if there are possibility for improve character's stats
            if(infos.playerData.statsRequiredVitality != 0)
                ui->pushButtonAddVitality->setEnabled(true);
            else
                ui->pushButtonAddVitality->setEnabled(false);

            if(infos.playerData.statsRequiredWisdom != 0)
                ui->pushButtonAddWisdom->setEnabled(true);
            else
                ui->pushButtonAddWisdom->setEnabled(false);

            if(infos.playerData.statsRequiredStrength != 0)
                ui->pushButtonAddStrength->setEnabled(true);
            else
                ui->pushButtonAddStrength->setEnabled(false);

            if(infos.playerData.statsRequiredIntelligence != 0)
                ui->pushButtonAddIntelligence->setEnabled(true);
            else
                ui->pushButtonAddIntelligence->setEnabled(false);

            if(infos.playerData.statsRequiredChance != 0)
                ui->pushButtonAddChance->setEnabled(true);
            else
                ui->pushButtonAddChance->setEnabled(false);

            if(infos.playerData.statsRequiredAgility != 0)
                ui->pushButtonAddAgility->setEnabled(true);
            else
                ui->pushButtonAddAgility->setEnabled(false);
        }

        else
        {
            ui->pushButtonAddVitality->setEnabled(false);
            ui->pushButtonAddWisdom->setEnabled(false);
            ui->pushButtonAddStrength->setEnabled(false);
            ui->pushButtonAddIntelligence->setEnabled(false);
            ui->pushButtonAddChance->setEnabled(false);
            ui->pushButtonAddAgility->setEnabled(false);
        }


        if(infos.playerData.stats[(uint)StatIds::VITALITY].base == 0 && infos.playerData.stats[(uint)StatIds::WISDOM].base == 0 && infos.playerData.stats[(uint)StatIds::STRENGTH].base == 0 && infos.playerData.stats[(uint)StatIds::INTELLIGENCE].base == 0 && infos.playerData.stats[(uint)StatIds::CHANCE].base == 0 && infos.playerData.stats[(uint)StatIds::AGILITY].base == 0)
            ui->pushButtonResetCharacteristics->setEnabled(false);
        else
            ui->pushButtonResetCharacteristics->setEnabled(true);


        // Characteristic's automatic booster
        switch (ui->comboBoxBoostAuto->currentIndex())
        {
        case INVALID:
            break;

        case 1:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredVitality != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::VITALITY);
            break;

        case 2:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredWisdom != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::WISDOM);
            break;

        case 3:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredStrength != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::STRENGTH);
            break;

        case 4:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredIntelligence != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::INTELLIGENCE);
            break;

        case 5:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredChance != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::CHANCE);
            break;

        case 6:
            if(infos.playerData.stats[(uint)StatIds::STATS_POINTS].base != 0 && infos.playerData.statsRequiredAgility != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::AGILITY);
            break;
        }


        // Spell's list
        uint levelSpell = 0;

        if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
            levelSpell = infos.mapData.playersOnMap[infos.mapData.botId].level;

        else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
            levelSpell = infos.fightData.fighters[infos.fightData.botFightData.botId].level;

        //bool newSpells = ui->tableWidget->it != infos.playerData.spells.size();

        ui->tableWidgetSpells->clearContents();
        ui->tableWidgetSpells->setRowCount(0);
        ui->tableWidgetSpells->removeRow(0);
        QSharedPointer<SpellData> spellData;
        foreach(const Spell &spell, infos.playerData.spells)
        {
            spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spell.spellID));
            ui->tableWidgetSpells->insertRow(ui->tableWidgetSpells->rowCount());
            ui->tableWidgetSpells->setItem(ui->tableWidgetSpells->rowCount()-1, 0, new QTableWidgetItem(QString::number(spellData->getId())));
            ui->tableWidgetSpells->setItem(ui->tableWidgetSpells->rowCount()-1, 1, new QTableWidgetItem(spellData->getName()));
            ui->tableWidgetSpells->setItem(ui->tableWidgetSpells->rowCount()-1, 2, new QTableWidgetItem(QString::number(spell.spellLevel)));
        }


        // Job's list
        ui->tableWidgetJobs->clearContents();
        ui->tableWidgetJobs->setRowCount(0);
        ui->tableWidgetJobs->removeRow(0);
        QSharedPointer<JobData> jobData;
        foreach(const JobExperience &e, infos.craftData.jobs)
        {
            //qDebug() << "Name job:" << jobData->getName();
            if(e.jobLevel != 1 && (qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor)))) != 0)
            {
                jobData = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, e.jobId));
                ui->tableWidgetJobs->insertRow(ui->tableWidgetJobs->rowCount());
                ui->tableWidgetJobs->setItem(ui->tableWidgetJobs->rowCount()-1, 0, new QTableWidgetItem(QString::number(jobData->getId())));
                ui->tableWidgetJobs->setItem(ui->tableWidgetJobs->rowCount()-1, 1, new QTableWidgetItem(jobData->getName()));
                ui->tableWidgetJobs->setItem(ui->tableWidgetJobs->rowCount()-1, 2, new QTableWidgetItem(QString::number(e.jobLevel)));
                ui->tableWidgetJobs->setItem(ui->tableWidgetJobs->rowCount()-1, 3, new QTableWidgetItem(QString("%1% (%2/%3)").arg(qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor)))).arg(e.jobXP).arg(e.jobXpNextLevelFloor)));

            }
        }
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }
}

void CharacterForm::loadCharacterFullUrl(QNetworkReply *reply)
{
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    ui->labelImage->setPixmap(pixmap);
    reply->deleteLater();
}

void CharacterForm::loadCharacterFaceUrl(QNetworkReply *reply)
{
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    m_engine->getStatsManager().defineSkinHead(m_sender, pixmap);
    reply->deleteLater();
}

void CharacterForm::on_pushButtonAddVitality_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::VITALITY);
}

void CharacterForm::on_pushButtonAddWisdom_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::WISDOM);
}

void CharacterForm::on_pushButtonAddStrength_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::STRENGTH);
}

void CharacterForm::on_pushButtonAddIntelligence_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::INTELLIGENCE);
}

void CharacterForm::on_pushButtonAddChance_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::CHANCE);
}

void CharacterForm::on_pushButtonAddAgility_clicked()
{
    m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::AGILITY);
}

void CharacterForm::on_pushButtonResetCharacteristics_clicked()
{
    int answ = QMessageBox::warning(this, "Warning", "Are you sur you want to reset your characteristics?", QMessageBox::Yes | QMessageBox::No);
    if(answ == QMessageBox::Yes)
        m_engine->getStatsManager().resetStat(m_sender);
}
