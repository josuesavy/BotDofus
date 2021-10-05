#include "statisticsform.h"
#include "ui_statisticsform.h"

StatisticsForm::StatisticsForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;
}

StatisticsForm::~StatisticsForm()
{
    delete ui;
}

SocketIO *StatisticsForm::getSocket()
{
    return m_sender;
}

ConnectionInfos StatisticsForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &StatisticsForm::getData() const
{
    return m_engine->getData(m_sender);
}

void StatisticsForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ui->treeWidget->clear();

        if(infos.statisticsData.countTotalExperience != 0 || infos.statisticsData.countTotalExperienceJobs.size() != 0 || infos.statisticsData.countTotalExperienceMount != 0 || infos.statisticsData.countTotalExperienceGuild != 0 || infos.statisticsData.countTotalExperienceIncarnation != 0 || infos.statisticsData.countTotalGetNewLevel != 0 || infos.statisticsData.countTotalGetNewLevelJobs.size() != 0 || infos.statisticsData.countTotalPointVitality != 0 || infos.statisticsData.countTotalPointWisdom != 0 || infos.statisticsData.countTotalPointStrength != 0 || infos.statisticsData.countTotalPointIntelligence != 0 || infos.statisticsData.countTotalPointChance != 0 || infos.statisticsData.countTotalPointAgility != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Characteristics");

            if(infos.statisticsData.countTotalExperience != 0 || infos.statisticsData.countTotalExperienceJobs.size() != 0)
            {
                // Process total xp jobs
                int totalExperiencesJobs = 0;
                foreach(int value, infos.statisticsData.countTotalExperienceJobs.values())
                    totalExperiencesJobs += value;

                // Add and display total xp jobs+bot
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total experiences: %1").arg(infos.statisticsData.countTotalExperience + totalExperiencesJobs));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalExperience != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Character: %1").arg(infos.statisticsData.countTotalExperience));
                    subItem->addChild(subSubItem);
                    //subItem->addChild(new QTreeWidgetItem(QStringList(QString("Personnage : %1").arg(infos.statisticsData.countTotalExperience))));
                }

                if(infos.statisticsData.countTotalExperienceJobs.size() != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, "Job");
                    subItem->addChild(subItem);

                    QMapIterator<int, int> module(infos.statisticsData.countTotalExperienceJobs);
                    while (module.hasNext())
                    {
                        module.next();

                        QSharedPointer<JobData> jobData = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, module.key()));

                        QTreeWidgetItem *subSubSubItem2 = new QTreeWidgetItem(subSubItem);
                        subSubSubItem2->setText(0, QString("%1 : %2").arg(jobData->getName()).arg(module.value()));
                        subSubItem->addChild(subSubSubItem2);
                    }
                }
            }

            if(infos.statisticsData.countTotalExperienceMount != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Mount: %1").arg(infos.statisticsData.countTotalExperienceMount));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalExperienceGuild != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Guild: %1").arg(infos.statisticsData.countTotalExperienceGuild));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalExperienceIncarnation != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Incarnation: %1").arg(infos.statisticsData.countTotalExperienceIncarnation));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalGetNewLevel != 0 || infos.statisticsData.countTotalGetNewLevelJobs.size() != 0)
            {
                // Process total xp jobs
                int totalLevelsJobs = 0;
                foreach(int value, infos.statisticsData.countTotalGetNewLevelJobs.values())
                    totalLevelsJobs += value;

                // Add and display total xp jobs+bot
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Number of levels taken in total: %1").arg(infos.statisticsData.countTotalGetNewLevel + totalLevelsJobs));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalGetNewLevel != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Character: %1").arg(infos.statisticsData.countTotalGetNewLevel));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalGetNewLevelJobs.size() != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, "Job");
                    subItem->addChild(subItem);

                    QMapIterator<int, int> module(infos.statisticsData.countTotalGetNewLevelJobs);
                    while (module.hasNext())
                    {
                        module.next();

                        QSharedPointer<JobData> jobData = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, module.key()));

                        QTreeWidgetItem *subSubSubItem = new QTreeWidgetItem(subSubItem);
                        subSubSubItem->setText(0, QString("%1: %2").arg(jobData->getName()).arg(module.value()));
                        subSubItem->addChild(subSubSubItem);
                    }
                }
            }

            if(infos.statisticsData.countTotalPointVitality != 0 || infos.statisticsData.countTotalPointWisdom != 0 || infos.statisticsData.countTotalPointStrength != 0 || infos.statisticsData.countTotalPointIntelligence != 0 || infos.statisticsData.countTotalPointChance != 0 || infos.statisticsData.countTotalPointAgility != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total number of characteristic points: %1").arg(infos.statisticsData.countTotalPointVitality + infos.statisticsData.countTotalPointWisdom + infos.statisticsData.countTotalPointStrength + infos.statisticsData.countTotalPointIntelligence + infos.statisticsData.countTotalPointChance + infos.statisticsData.countTotalPointAgility));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalPointVitality != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Vitality: %1").arg(infos.statisticsData.countTotalPointVitality));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalPointWisdom != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Wisdom: %1").arg(infos.statisticsData.countTotalPointWisdom));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalPointStrength != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Strength: %1").arg(infos.statisticsData.countTotalPointStrength));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalPointIntelligence != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Intelligence: %1").arg(infos.statisticsData.countTotalPointIntelligence));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalPointChance != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Chance: %1").arg(infos.statisticsData.countTotalPointChance));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalPointAgility != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Agility: %1").arg(infos.statisticsData.countTotalPointAgility));
                    subItem->addChild(subSubItem);
                }
            }

            ui->treeWidget->expandItem(item);
        }

        if(infos.statisticsData.countTotalResourcesFight != 0 || infos.statisticsData.countTotalResourcesGather != 0 || infos.statisticsData.countTotalObjectWonFight != 0 || infos.statisticsData.countTotalObjectWonGather != 0 || infos.statisticsData.countTotalKamas != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Inventory");
            ui->treeWidget->addTopLevelItem(item);

            if(infos.statisticsData.countTotalResourcesFight != 0 || infos.statisticsData.countTotalResourcesGather != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total resources: %1").arg(infos.statisticsData.countTotalResourcesFight + infos.statisticsData.countTotalResourcesGather));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalResourcesFight != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Fight: %1").arg(infos.statisticsData.countTotalResourcesFight));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalResourcesGather != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Harvest: %1").arg(infos.statisticsData.countTotalResourcesGather));
                    subItem->addChild(subSubItem);
                }
            }

            if(infos.statisticsData.countTotalObjectWonFight != 0 || infos.statisticsData.countTotalObjectWonGather != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total objects: %1").arg(infos.statisticsData.countTotalObjectWonFight + infos.statisticsData.countTotalObjectWonGather));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalObjectWonFight != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Fight: %1").arg(infos.statisticsData.countTotalObjectWonFight));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalObjectWonGather != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Harvest: %1").arg(infos.statisticsData.countTotalObjectWonGather));
                    subItem->addChild(subSubItem);
                }
            }

            if(infos.statisticsData.countTotalKamas != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total kamas: %1").arg(infos.statisticsData.countTotalKamas));
                item->addChild(subItem);
            }
        }

        if(infos.statisticsData.countFightSetWon != 0 || infos.statisticsData.countFightSetLost != 0 || infos.statisticsData.countFightGetWon != 0 || infos.statisticsData.countFightGetLost != 0 || infos.statisticsData.speedFight != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Fights");
            ui->treeWidget->addTopLevelItem(item);

            if(infos.statisticsData.countFightSetWon != 0 || infos.statisticsData.countFightSetLost != 0 || infos.statisticsData.countFightGetWon != 0 || infos.statisticsData.countFightGetLost != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total fights: %1").arg(infos.statisticsData.countFightSetWon + infos.statisticsData.countFightSetLost + infos.statisticsData.countFightGetWon + infos.statisticsData.countFightGetLost));
                item->addChild(subItem);

                if(infos.statisticsData.countFightSetWon != 0 || infos.statisticsData.countFightSetLost != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Launch: %1").arg(infos.statisticsData.countFightSetWon + infos.statisticsData.countFightSetLost));
                    subItem->addChild(subSubItem);

                    if(infos.statisticsData.countFightSetWon != 0)
                    {
                        QTreeWidgetItem *subSubSubItem = new QTreeWidgetItem(subSubItem);
                        subSubSubItem->setText(0, QString("Wins: %1").arg(infos.statisticsData.countFightSetWon));
                        subSubItem->addChild(subSubSubItem);
                    }

                    if(infos.statisticsData.countFightSetLost != 0)
                    {
                        QTreeWidgetItem *subSubSubItem = new QTreeWidgetItem(subSubItem);
                        subSubSubItem->setText(0, QString("Losts: %1").arg(infos.statisticsData.countFightSetLost));
                        subSubItem->addChild(subSubSubItem);
                    }
                }

                if(infos.statisticsData.countFightGetWon != 0 || infos.statisticsData.countFightGetLost != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Received: %1").arg(infos.statisticsData.countFightGetWon + infos.statisticsData.countFightGetLost));
                    subItem->addChild(subSubItem);

                    if(infos.statisticsData.countFightGetWon != 0)
                    {
                        QTreeWidgetItem *subSubSubItem = new QTreeWidgetItem(subSubItem);
                        subSubSubItem->setText(0, QString("Wins: %1").arg(infos.statisticsData.countFightGetWon));
                        subSubItem->addChild(subSubSubItem);
                    }

                    if(infos.statisticsData.countFightGetLost != 0)
                    {
                        QTreeWidgetItem *subSubSubItem = new QTreeWidgetItem(subSubItem);
                        subSubSubItem->setText(0, QString("Losts: %1").arg(infos.statisticsData.countFightGetLost));
                        subSubItem->addChild(subSubSubItem);
                    }
                }

                if(infos.statisticsData.speedFight != 0)
                {
                    QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                    subItem->setText(0, QString("Average speed: %1").arg(infos.statisticsData.speedFight / (infos.statisticsData.countFightSetWon+infos.statisticsData.countFightSetLost+infos.statisticsData.countFightGetWon+infos.statisticsData.countFightGetLost)));
                    item->addChild(subItem);
                }
            }
        }

        if(infos.statisticsData.countTotalGatherWon != 0 || infos.statisticsData.countTotalGatherLost != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Harvest");
            ui->treeWidget->addTopLevelItem(item);

            QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
            subItem->setText(0, QString("Harvest total: %1").arg(infos.statisticsData.countTotalGatherWon + infos.statisticsData.countTotalGatherLost));
            item->addChild(subItem);

            if(infos.statisticsData.countTotalGatherWon != 0)
            {
                QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                subSubItem->setText(0, QString("Win: %1").arg(infos.statisticsData.countTotalGatherWon));
                subItem->addChild(subSubItem);
            }

            if(infos.statisticsData.countTotalGatherLost != 0)
            {
                QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                subSubItem->setText(0, QString("Lost: %1").arg(infos.statisticsData.countTotalGatherLost));
                subItem->addChild(subSubItem);
            }
        }

        if(infos.statisticsData.countTotalMessageSent != 0 || infos.statisticsData.countTotalMessageFailed != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Flood");
            ui->treeWidget->addTopLevelItem(item);

            QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
            subItem->setText(0, QString("Total messages: %1").arg(infos.statisticsData.countTotalMessageSent + infos.statisticsData.countTotalMessageFailed));
            item->addChild(subItem);

            if(infos.statisticsData.countTotalMessageSent != 0)
            {
                QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                subSubItem->setText(0, QString("Successful: %1").arg(infos.statisticsData.countTotalMessageSent));
                subItem->addChild(subSubItem);
            }

            if(infos.statisticsData.countTotalMessageFailed != 0)
            {
                QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                subSubItem->setText(0, QString("Failed: %1").arg(infos.statisticsData.countTotalMessageFailed));
                subItem->addChild(subSubItem);
            }
        }

        if(infos.statisticsData.countTotalReconnection != 0 || infos.statisticsData.countTotalNotValidatedAchievement != 0 || infos.statisticsData.countTotalValidatedAchievement != 0 || infos.statisticsData.countTotalMetPlayers.size() != 0 || infos.statisticsData.countTotalSpeedNetwork != 0 || infos.statisticsData.countTotalBackToBank != 0 || infos.statisticsData.countTotalBackToPhoenix != 0 || infos.statisticsData.countTotalRestartScript != 0 || infos.statisticsData.countTotalValidatedQuest != 0 || infos.statisticsData.countTotalNewQuest != 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Miscellaneous");

            if(infos.statisticsData.countTotalReconnection != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total reconnection: %1").arg(infos.statisticsData.countTotalReconnection));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalNotValidatedAchievement != 0 || infos.statisticsData.countTotalValidatedAchievement != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total successful: %1").arg(infos.statisticsData.countTotalNotValidatedAchievement + infos.statisticsData.countTotalValidatedAchievement));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalValidatedAchievement != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Accepted: %1").arg(infos.statisticsData.countTotalValidatedAchievement));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalNotValidatedAchievement != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Not accepted: %1").arg(infos.statisticsData.countTotalNotValidatedAchievement));
                    subItem->addChild(subSubItem);
                }
            }

            if(infos.statisticsData.countTotalMetPlayers.size() != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total people met: %1").arg(infos.statisticsData.countTotalMetPlayers.size()));
                item->addChild(subItem);
            }

            if(m_sender->getLatencyAverage() != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Average network speed: %1 ms").arg(m_sender->getLatencyAverage())); // Faire le calcul
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalBackToBank != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Number of returns to the bank: %1").arg(infos.statisticsData.countTotalBackToBank));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalBackToPhoenix != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Number of return to Phoenix: %1").arg(infos.statisticsData.countTotalBackToPhoenix));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalRestartScript != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Number of script restart: %1").arg(infos.statisticsData.countTotalRestartScript));
                item->addChild(subItem);
            }

            if(infos.statisticsData.countTotalValidatedQuest != 0 || infos.statisticsData.countTotalNewQuest != 0)
            {
                QTreeWidgetItem *subItem = new QTreeWidgetItem(item);
                subItem->setText(0, QString("Total quests: %1").arg(infos.statisticsData.countTotalValidatedQuest + infos.statisticsData.countTotalNewQuest));
                item->addChild(subItem);

                if(infos.statisticsData.countTotalValidatedQuest != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("New: %1").arg(infos.statisticsData.countTotalValidatedQuest));
                    subItem->addChild(subSubItem);
                }

                if(infos.statisticsData.countTotalNewQuest != 0)
                {
                    QTreeWidgetItem *subSubItem = new QTreeWidgetItem(subItem);
                    subSubItem->setText(0, QString("Validate: %1").arg(infos.statisticsData.countTotalNewQuest));
                    subItem->addChild(subSubItem);
                }
            }

            ui->treeWidget->addTopLevelItem(item);
        }

        // Expand all items
        if(ui->treeWidget->topLevelItemCount())
        {
            for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
            {
                ui->treeWidget->topLevelItem(i)->setExpanded(true);
                if(ui->treeWidget->topLevelItem(i)->childCount())
                {
                    for(int j = 0; j < ui->treeWidget->topLevelItem(i)->childCount(); j++)
                    {
                        ui->treeWidget->topLevelItem(i)->child(j)->setExpanded(true);
                        if(ui->treeWidget->topLevelItem(i)->child(j)->childCount())
                        {
                            for(int k = 0; k < ui->treeWidget->topLevelItem(i)->child(j)->childCount(); k++)
                            {
                                ui->treeWidget->topLevelItem(i)->child(j)->child(k)->setExpanded(true);
    //                            if(ui->treeWidget->topLevelItem(i)->child(j)->child(k)->childCount())
    //                            {
    //                                for(int l = 0; k < ui->treeWidget->topLevelItem(i)->child(j)->child(k)->childCount(); l++)
    //                                {
    //                                    ui->treeWidget->topLevelItem(i)->child(j)->child(k)->child(l)->setExpanded(true);
    //                                }
    //                            }
                            }
                        }
                    }
                }
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
