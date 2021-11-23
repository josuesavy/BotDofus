#include "accountform.h"
#include "ui_accountform.h"

AccountForm::AccountForm(ProcessEngine *engine, const ConnectionInfos &infos, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = m_engine->getConnectionManager().addConnection(m_infos);

    consoleForm = new ConsoleForm(m_engine, m_infos, m_sender, this);
    characterForm = new CharacterForm(m_engine, m_infos, m_sender, this);
    inventoryForm = new InventoryForm(m_engine, m_infos, m_sender, this);
    mapForm = new MapForm(m_engine, m_infos, m_sender, this);
    floodForm = new FloodForm(m_engine, m_infos, m_sender, this);
    fightForm = new FightForm(m_engine, m_infos, m_sender, this);
    statisticsForm = new StatisticsForm(m_engine, m_infos, m_sender, this);
    settingsForm = new SettingsForm(m_engine, m_infos, m_sender, this);

    // Initialisation des tabs
    ui->tabWidget->addTab(consoleForm,QIcon(":/icons/text_align_left_16px.ico"),"Console");
    ui->tabWidget->addTab(characterForm,QIcon(":/icons/user_16px.ico"),"Character");
    ui->tabWidget->addTab(inventoryForm,QIcon(":/icons/luggage_brown_16px.ico"),"Inventory");
    ui->tabWidget->addTab(mapForm,QIcon(":/icons/map_16px.ico"),"Map");
    ui->tabWidget->addTab(floodForm,QIcon(":/icons/comment_16px.ico"),"Flood");
    ui->tabWidget->addTab(fightForm,QIcon(":/icons/sword_16px.ico"),"Fight");
    ui->tabWidget->addTab(statisticsForm,QIcon(":/icons/statistics_16px.ico"),"Statistics");
    ui->tabWidget->addTab(settingsForm,QIcon(":/icons/cog_16px.ico"),"Settings");
    ui->tabWidget->setCurrentIndex(0);

    updateInterface();

    if(m_infos.masterGroup.isEmpty())
    {
        menuScript = new QMenu;

        QString num; // TODO : Doit contenir le path en settings
        if(num.isEmpty())
            menuScript->addAction(ui->actionLoadScript);
        else
        {
            menuScript->addAction(ui->actionLoadScript);
            menuScript->addAction(ui->actionRunScript);
        }
        ui->pushButtonFile->setMenu(menuScript);

        ui->pushButtonGroupSettings->hide();
    }

    else if(!m_infos.masterGroup.isEmpty() && m_infos.masterGroup == m_infos.character)
    {
        menuScript = new QMenu;
        menuGroupSettings = new QMenu;

        QString num; // TODO : Doit contenir le path en settings
        if(num.isEmpty())
            menuScript->addAction(ui->actionLoadScript);
        else
        {
            menuScript->addAction(ui->actionLoadScript);
            menuScript->addAction(ui->actionRunScript);
        }
        ui->pushButtonFile->setMenu(menuScript);

        menuGroupSettings->addAction(ui->actionTeleportSlavesToMaster);
        ui->pushButtonGroupSettings->setMenu(menuGroupSettings);
    }

    else if(!m_infos.masterGroup.isEmpty() && m_infos.masterGroup != m_infos.character)
    {
        menuGroupSettings = new QMenu;

        menuGroupSettings->addAction(ui->actionTeleportSlavesToMaster);
        ui->pushButtonGroupSettings->setMenu(menuGroupSettings);

        ui->pushButtonFile->hide();
        ui->pushButtonClose->hide();
    }

    //QObject::connect(&m_updateTimer, &QTimer::timeout, [this] () { updateInterface(true); });
}

AccountForm::~AccountForm()
{
    m_engine->getConnectionManager().removeConnection(m_sender);
    delete consoleForm;
    delete characterForm;
    delete inventoryForm;
    delete mapForm;
    delete floodForm;
    delete fightForm;
    delete statisticsForm;
    delete settingsForm;
    delete ui;
}

SocketIO *AccountForm::getSocket()
{
    return m_sender;
}

ConnectionInfos AccountForm::getConnectionInfos()
{
    return m_infos;
}

const BotData &AccountForm::getData() const
{
    return m_engine->getData(m_sender);
}

ProcessEngine *AccountForm::getEngine()
{
    return m_engine;
}

ConsoleForm *AccountForm::getConsoleForm()
{
    return consoleForm;
}

CharacterForm *AccountForm::getCharacterForm()
{
    return characterForm;
}

InventoryForm *AccountForm::getInventoryForm()
{
    return inventoryForm;
}

MapForm *AccountForm::getMapForm()
{
    return mapForm;
}

FloodForm *AccountForm::getFloodForm()
{
    return floodForm;
}

FightForm *AccountForm::getFightForm()
{
    return fightForm;
}

SettingsForm *AccountForm::getSettingsForm()
{
    return settingsForm;
}

QList<AccountForm *> AccountForm::getAccountFormChilds()
{
    return m_accountFormChilds;
}

void AccountForm::setAccountFormChilds(QList<AccountForm *> accountForms)
{
    m_accountFormChilds = accountForms;
}

void AccountForm::loadScript(QString path)
{
    menuScript->clear(); // Reinitialisation du menu

    ui->pushButtonFile->setText(QFileInfo(path).fileName());

    if(!path.isEmpty())
    {
        menuScript->addAction(ui->actionLoadScript);
        menuScript->addAction(ui->actionRunScript);
        m_path = path;

        m_engine->info(m_sender) << "Script loaded.";
    }
    else
    {
        menuScript->addAction(ui->actionLoadScript);

        m_engine->info(m_sender) << "Script unloaded.";
    }

    ui->pushButtonFile->setMenu(menuScript);
}

int AccountForm::loadPath(QString path, bool unload)
{
    //    if (!unload)
    //    {
    //        if (!m_engine->getScriptModule().loadFile(m_sender, path))
    //            return INVALID;

    //        uint i = m_engine->getScriptModule().parse(m_sender);
    //        if (i)
    //            return i;

    //        m_engine->getGroupModule().setFollowUpEnabled(m_sender, false);
    //        m_engine->getScriptModule().setActivePath(m_sender, true);

    //        return 0;
    //    }

    //    else
    //    {
    //        m_engine->getScriptModule().unloadFile(m_sender);
    //        return 0;
    //    }
    return 0;
}

void AccountForm::autoConnect()
{
    emit ui->pushButtonDisconnection->clicked();
}

void AccountForm::updateInterface(bool directCall)
{
//    if(m_updateChecker.elapsed() < UPDATE_INTERVAL && directCall)
//    {
//        if(!m_updateTimer.isActive())
//        {
//            m_updateTimer.setInterval(UPDATE_INTERVAL-m_updateChecker.elapsed());
//            m_updateTimer.start();
//        }

//        return;
//    }

    consoleForm->updateInterface();
    characterForm->updateInterface();
    inventoryForm->updateInterface();
    mapForm->updateInterface();
    floodForm->updateInterface();
    fightForm->updateInterface();
    statisticsForm->updateInterface();
    settingsForm->updateInterface();

    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ui->pushButtonDisconnection->setIcon(QIcon(":/icons/disconnect_16px.ico"));
        ui->pushButtonDisconnection->setToolTip(tr("Déconnexion"));

        for(int i = 1; i <= ui->tabWidget->count()-2; i++)
            ui->tabWidget->setTabEnabled(i, true);

        ui->labelIconEnergy->setEnabled(true);
        ui->progressBarEnergy->setEnabled(true);
        ui->progressBarEnergy->setFormat("%v/%m (%p%)");

        ui->labelIconLife->setEnabled(true);
        ui->progressBarLife->setEnabled(true);
        ui->progressBarLife->setFormat("%v/%m (%p%)");

        ui->labelIconPods->setEnabled(true);
        ui->progressBarPods->setEnabled(true);
        ui->progressBarPods->setFormat("%v/%m (%p%)");

        ui->labelIconExperience->setEnabled(true);
        ui->progressBarExperience->setEnabled(true);
        ui->labelIconKamas->setEnabled(true);


        if (infos.mapData.playersOnMap.contains(infos.mapData.botId) || infos.fightData.fighters.contains(infos.fightData.botFightData.botId))
        {
            QSharedPointer<SubAreaData> subAreas = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, infos.mapData.map.getSubAreaId()));
            QString area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subAreas->getAreaId()))->getName();

            ui->labelInfosPosition->setText(QString("<b>[%1,%2]</b> %3 (%4)").arg(infos.mapData.map.getPosition().getX()).arg(infos.mapData.map.getPosition().getY()).arg(area).arg(subAreas->getName()));

            if (infos.connectionData.connectionInfos.character != infos.connectionData.connectionInfos.masterGroup && infos.groupData.master == "" && !infos.connectionData.connectionInfos.masterGroup.isEmpty())
                    m_engine->getGroupManager().setMaster(m_sender, infos.connectionData.connectionInfos.masterGroup);

            // Experience du personnage
            if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
                ui->progressBarExperience->setFormat(QString("%1 (%p%)").arg(infos.mapData.playersOnMap[infos.mapData.botId].level));

            else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
                ui->progressBarExperience->setFormat(QString("%1 (%p%)").arg(infos.fightData.fighters[infos.fightData.botFightData.botId].level));

            ui->progressBarExperience->setMaximum(infos.playerData.experienceNextLevelFloor-infos.playerData.experienceLevelFloor);
            ui->progressBarExperience->setValue(infos.playerData.experience-infos.playerData.experienceLevelFloor);
        }

        // Abonnement du personnage
        if(infos.playerData.subscriptionEndDate == INVALID)
            ui->labelSubscriptionDofus->setText(tr("N/A"));

        else if(infos.playerData.subscriptionEndDate != 0)
            ui->labelSubscriptionDofus->setText(dateToString(infos.playerData.subscriptionEndDate));

        else
            ui->labelSubscriptionDofus->setText(D2OManagerSingleton::get()->getI18N()->getText("ui.common.non_subscriber"));

        // Status du personnage
        switch (getData().generalData.botState)
        {
        case BotState::MOVING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Moving"));
        }
            break;
        case BotState::MAP_TRANSITION_STATE:
        case BotState::CALCULATING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_red_16px.ico"));
            ui->labelStatus->setText(tr("Busy"));
        }
            break;
        case BotState::FARMING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Harvest"));
        }
            break;
        case BotState::BANKING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Bank"));
        }
            break;
        case BotState::INVALID_STATE:
            ui->labelStatus->setText(tr("Invalid"));
            break;
        case BotState::CRAFTING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Craft"));
        }
            break;
        case BotState::FIGHTING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Fight"));
        }
            break;
        case BotState::INACTIVE_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Inactive"));
        }
            break;
        case BotState::EXCHANGING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Exchange"));
        }
            break;
        case BotState::REGENERATING_STATE:
        {
            ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_green_16px.ico"));
            ui->labelStatus->setText(tr("Regeneration"));
        }
            break;
        }


        // Energie du personnage
        ui->progressBarEnergy->setMaximum(infos.playerData.stats[(uint)StatIds::MAX_ENERGY_POINTS].total);
        ui->progressBarEnergy->setValue(infos.playerData.stats[(uint)StatIds::ENERGY_POINTS].total);


        // Vie du personnage
        if (m_engine->getStatsManager().getShieldPoints(m_sender) > 0)
            ui->progressBarLife->setFormat(QString("%v/%m (%p%) (%1)").arg(m_engine->getStatsManager().getShieldPoints(m_sender)));
        else
            ui->progressBarLife->setFormat("%v/%m (%p%)");

        ui->progressBarLife->setMaximum(m_engine->getStatsManager().getMaxHealthPoints(m_sender));
        ui->progressBarLife->setValue(m_engine->getStatsManager().getHealthPoints(m_sender));


        // Pods du personnage
        ui->progressBarPods->setMaximum(infos.playerData.pods.max);
        ui->progressBarPods->setValue(infos.playerData.pods.current);


        // Kamas du personnage
        ui->labelKamas->setText(QString("%1 <b>₭</b>").arg(infos.playerData.kamas));
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        ui->pushButtonDisconnection->setIcon(QIcon(":/icons/connect_16px.ico"));
        ui->pushButtonDisconnection->setToolTip(tr("Connection"));

        for(int i = 1; i <= ui->tabWidget->count()-2; i++)
            ui->tabWidget->setTabEnabled(i, false);

        ui->labelSubscriptionDofus->clear();
        ui->labelInfosPosition->clear();

        ui->labelIconEnergy->setEnabled(false);
        ui->progressBarEnergy->setValue(0);
        ui->progressBarEnergy->setEnabled(false);
        ui->progressBarEnergy->setFormat("");
        ui->labelIconLife->setEnabled(false);
        ui->progressBarLife->setValue(0);
        ui->progressBarLife->setEnabled(false);
        ui->progressBarLife->setFormat("");
        ui->labelIconPods->setEnabled(false);
        ui->progressBarPods->setValue(0);
        ui->progressBarPods->setEnabled(false);
        ui->progressBarPods->setFormat("");
        ui->labelIconExperience->setEnabled(false);
        ui->progressBarExperience->setValue(0);
        ui->progressBarExperience->setEnabled(false);
        ui->progressBarExperience->setFormat("");
        ui->labelIconKamas->setEnabled(false);
        ui->labelKamas->clear();

        ui->labelIconStatus->setPixmap(QPixmap(":/icons/bullet_red_16px.ico"));
        ui->labelStatus->setText(tr("Disconnected"));
    }

    //m_updateChecker.restart();
}

void AccountForm::on_pushButtonDisconnection_clicked()
{
    if(!m_sender->isActive())
        m_engine->getConnectionManager().connect(m_sender);

    else
        m_engine->getConnectionManager().disconnect(m_sender);
}

void AccountForm::on_actionLoadScript_triggered()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Select a file");

    loadScript(path);
}

void AccountForm::on_actionRunScript_triggered()
{
    if(ui->actionRunScript->text() == "Start the script")
    {
        bool p = false;

        int result = loadPath(m_path, false);

        if (result == INVALID)
            m_engine->error(m_sender) << "[Script] Nous n'avons pas réussit a ouvrir le fichier du trajet, le chargement des trajets a été interrompu veuillez recommencer après avoir corrigé l'erreur";
        else if (result != 0)
            m_engine->error(m_sender) << "[Script] Erreur à la ligne :" << QString::number(result);

        if (result == INVALID || result != 0)
            p = true;

        if (!p)
        {
            ui->actionRunScript->setIcon(QIcon(":/icons/script_delete_16px.ico"));
            ui->actionRunScript->setText(tr("Stop the script"));
        }
    }
    else if(ui->actionRunScript->text() == "Stop the script")
    {
        loadPath(QString(), true);

        ui->actionRunScript->setIcon(QIcon(":/icons/script_go_16px.ico"));
        ui->actionRunScript->setText(tr("Start the script"));
    }
}

void AccountForm::on_pushButtonClose_clicked()
{
    if (m_sender->isActive())
    {
        int answ = QMessageBox::warning(this, "Warning", "Are you sur you want to close this account?\nIt's currently online.", QMessageBox::Yes | QMessageBox::No);
        if(answ == QMessageBox::Yes)
        {
            if(m_accountFormChilds.size())
            {
                foreach(AccountForm *accountForm, m_accountFormChilds)
                {
                    if (accountForm->getSocket()->isActive())
                        accountForm->getEngine()->getConnectionManager().disconnect(accountForm->getSocket());

                    emit remove(accountForm, true);
                }
            }
            m_engine->getConnectionManager().disconnect(m_sender);
            emit remove(this);
        }
    }

    else
    {
        if(m_accountFormChilds.size())
        {
            foreach(AccountForm *accountForm, m_accountFormChilds)
            {
                if (accountForm->getSocket()->isActive())
                    accountForm->getEngine()->getConnectionManager().disconnect(accountForm->getSocket());

                emit remove(accountForm, true);
            }
        }
        emit remove(this);
    }
}

void AccountForm::on_actionTeleportSlavesToMaster_triggered()
{
    if(m_engine->getData(m_sender).connectionData.connectionInfos.masterGroup != m_engine->getData(m_sender).connectionData.connectionInfos.character)
        m_engine->getGroupManager().teleportSlavesToMaster(m_sender, m_engine->getData(m_sender).connectionData.connectionInfos.masterGroup);

    else
    {
        foreach(SocketIO *slave, m_engine->getGroupManager().getSlaves(m_sender))
            m_engine->getGroupManager().teleportSlavesToMaster(slave, m_engine->getData(slave).connectionData.connectionInfos.masterGroup);
    }
}
