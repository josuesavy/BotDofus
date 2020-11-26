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
            ui->labelDescription->setText(QString("%1, Niveau %2").arg(breed->getShortName()).arg(infos.mapData.playersOnMap[infos.mapData.botId].level));
        }

        else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
        {
            QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, (int)infos.playerData.breed));
            ui->labelDescription->setText(QString("%1, Niveau %2").arg(breed->getShortName()).arg(infos.fightData.fighters[infos.fightData.botFightData.botId].level));
        }


        // Display character's characteristics
        ui->labelAP->setText(QString::number(infos.playerData.stats.actionPoints.base +
                                             infos.playerData.stats.actionPoints.alignGiftBonus +
                                             infos.playerData.stats.actionPoints.contextModif +
                                             infos.playerData.stats.actionPoints.objectsAndMountBonus +
                                             infos.playerData.stats.actionPoints.additionnal));
        ui->labelMP->setText(QString::number(infos.playerData.stats.movementPoints.base +
                                             infos.playerData.stats.movementPoints.alignGiftBonus +
                                             infos.playerData.stats.movementPoints.contextModif +
                                             infos.playerData.stats.movementPoints.objectsAndMountBonus +
                                             infos.playerData.stats.movementPoints.additionnal));
        ui->labelInitiative->setText(QString("%1/%2")
                                     .arg((infos.playerData.stats.initiative.base +infos.playerData.stats.initiative.alignGiftBonus +
                                           infos.playerData.stats.initiative.contextModif + infos.playerData.stats.initiative.objectsAndMountBonus +
                                           infos.playerData.stats.initiative.additionnal)*infos.playerData.stats.lifePoints / infos.playerData.stats.maxLifePoints)
                                     .arg(infos.playerData.stats.initiative.base + infos.playerData.stats.initiative.alignGiftBonus +
                                          infos.playerData.stats.initiative.contextModif + infos.playerData.stats.initiative.objectsAndMountBonus +
                                          infos.playerData.stats.initiative.additionnal));
        ui->labelProspecting->setText(QString::number(infos.playerData.stats.prospecting.base +
                                                      infos.playerData.stats.prospecting.alignGiftBonus +
                                                      infos.playerData.stats.prospecting.contextModif +
                                                      infos.playerData.stats.prospecting.objectsAndMountBonus +
                                                      infos.playerData.stats.prospecting.additionnal));
        ui->labelRange->setText(QString::number(infos.playerData.stats.range.base +
                                                infos.playerData.stats.range.alignGiftBonus +
                                                infos.playerData.stats.range.contextModif +
                                                infos.playerData.stats.range.objectsAndMountBonus +
                                                infos.playerData.stats.range.additionnal));
        ui->labelSummons->setText(QString::number(infos.playerData.stats.summonableCreaturesBoost.base +
                                                  infos.playerData.stats.summonableCreaturesBoost.alignGiftBonus +
                                                  infos.playerData.stats.summonableCreaturesBoost.contextModif +
                                                  infos.playerData.stats.summonableCreaturesBoost.objectsAndMountBonus +
                                                  infos.playerData.stats.summonableCreaturesBoost.additionnal));
        ui->labelVitality->setText(QString::number(infos.playerData.stats.vitality.base +
                                                   infos.playerData.stats.vitality.alignGiftBonus +
                                                   infos.playerData.stats.vitality.contextModif +
                                                   infos.playerData.stats.vitality.objectsAndMountBonus +
                                                   infos.playerData.stats.vitality.additionnal));
        ui->labelWisdom->setText(QString::number(infos.playerData.stats.wisdom.base +
                                                 infos.playerData.stats.wisdom.alignGiftBonus +
                                                 infos.playerData.stats.wisdom.contextModif +
                                                 infos.playerData.stats.wisdom.objectsAndMountBonus +
                                                 infos.playerData.stats.wisdom.additionnal));
        ui->labelStrength->setText(QString::number(infos.playerData.stats.strength.base +
                                                   infos.playerData.stats.strength.alignGiftBonus +
                                                   infos.playerData.stats.strength.contextModif +
                                                   infos.playerData.stats.strength.objectsAndMountBonus +
                                                   infos.playerData.stats.strength.additionnal));
        ui->labelIntelligence->setText(QString::number(infos.playerData.stats.intelligence.base +
                                                       infos.playerData.stats.intelligence.alignGiftBonus +
                                                       infos.playerData.stats.intelligence.contextModif +
                                                       infos.playerData.stats.intelligence.objectsAndMountBonus +
                                                       infos.playerData.stats.intelligence.additionnal));
        ui->labelChance->setText(QString::number(infos.playerData.stats.chance.base +
                                                 infos.playerData.stats.chance.alignGiftBonus +
                                                 infos.playerData.stats.chance.contextModif +
                                                 infos.playerData.stats.chance.objectsAndMountBonus +
                                                 infos.playerData.stats.chance.additionnal));
        ui->labelAgility->setText(QString::number(infos.playerData.stats.agility.base +
                                                  infos.playerData.stats.agility.alignGiftBonus +
                                                  infos.playerData.stats.agility.contextModif +
                                                  infos.playerData.stats.agility.objectsAndMountBonus +
                                                  infos.playerData.stats.agility.additionnal));
        ui->labelCapitalPoints->setText(QString("<b>%1</b>").arg(infos.playerData.stats.statsPoints));


        // Automatic booster
        if(infos.playerData.stats.statsPoints != 0)
        {
            // Enable buttons stats if there are possibility for improve character's stats
            if(infos.playerData.stats.statsRequiredVitality != 0)
                ui->pushButtonAddVitality->setEnabled(true);
            else
                ui->pushButtonAddVitality->setEnabled(false);

            if(infos.playerData.stats.statsRequiredWisdom != 0)
                ui->pushButtonAddWisdom->setEnabled(true);
            else
                ui->pushButtonAddWisdom->setEnabled(false);

            if(infos.playerData.stats.statsRequiredStrength != 0)
                ui->pushButtonAddStrength->setEnabled(true);
            else
                ui->pushButtonAddStrength->setEnabled(false);

            if(infos.playerData.stats.statsRequiredIntelligence != 0)
                ui->pushButtonAddIntelligence->setEnabled(true);
            else
                ui->pushButtonAddIntelligence->setEnabled(false);

            if(infos.playerData.stats.statsRequiredChance != 0)
                ui->pushButtonAddChance->setEnabled(true);
            else
                ui->pushButtonAddChance->setEnabled(false);

            if(infos.playerData.stats.statsRequiredAgility != 0)
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


        if(infos.playerData.stats.vitality.base == 0 && infos.playerData.stats.wisdom.base == 0 && infos.playerData.stats.strength.base == 0 && infos.playerData.stats.intelligence.base == 0 && infos.playerData.stats.chance.base == 0 && infos.playerData.stats.agility.base == 0)
            ui->pushButtonResetCharacteristics->setEnabled(false);
        else
            ui->pushButtonResetCharacteristics->setEnabled(true);


        // Characteristic's automatic booster
        switch (ui->comboBoxBoostAuto->currentIndex())
        {
        case INVALID:
            break;

        case 1:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredVitality != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::VITALITY);
            break;

        case 2:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredWisdom != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::WISDOM);
            break;

        case 3:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredStrength != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::STRENGTH);
            break;

        case 4:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredIntelligence != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::INTELLIGENCE);
            break;

        case 5:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredChance != 0)
                m_engine->getStatsManager().increaseStat(m_sender, PlayerD2OFields::CHANCE);
            break;

        case 6:
            if(infos.playerData.stats.statsPoints != 0 && infos.playerData.stats.statsRequiredAgility != 0)
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
    //qDebug() << "NetworkError:" << reply->error();

    QByteArray uii = reply->readAll();

    QPixmap pixmap;
    pixmap.loadFromData(uii);
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
    int answ = QMessageBox::warning(this, "Attention", "Etes-vous sûr de vouloir réinitialiser vos caractéristiques ?", QMessageBox::Yes | QMessageBox::No);
    if(answ == QMessageBox::Yes)
        m_engine->getStatsManager().resetStat(m_sender);
}
