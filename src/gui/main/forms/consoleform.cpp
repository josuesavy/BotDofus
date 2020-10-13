#include "consoleform.h"
#include "ui_consoleform.h"

ConsoleForm::ConsoleForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsoleForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    connect(this, SIGNAL(addConsoleLineRequest(QString)), this, SLOT(writeConsole(QString)));
}

ConsoleForm::~ConsoleForm()
{
    delete ui;
}

SocketIO *ConsoleForm::getSocket()
{
    return m_sender;
}

QString ConsoleForm::getTime(uint timeStamp)
{
    QString date = "";

    QTime time = QDateTime::fromTime_t(timeStamp).time();
    int hours = time.hour();
    int minutes = time.minute();
    int seconds = time.second();

    if (hours < 10)
        date += "0"+QString::number(hours);
    else
        date += QString::number(hours);

    date += ":";

    if (minutes < 10)
        date += "0"+QString::number(minutes);
    else
        date += QString::number(minutes);

    date += ":";

    if (seconds < 10)
        date += "0"+QString::number(seconds);
    else
        date += QString::number(seconds);

    return date;
}

ConnectionInfos ConsoleForm::getConnectionInfos() const
{
    return m_infos;
}

void ConsoleForm::updateInterface(bool directCall)
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ui->comboBoxCanal->setEnabled(true);
        ui->lineEditConsole->setEnabled(true);
        ui->pushButtonSmiley->setEnabled(true);
        ui->pushButtonSend->setEnabled(true);
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        ui->comboBoxCanal->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->pushButtonSmiley->setEnabled(false);
        ui->pushButtonSend->setEnabled(false);

        if(ui->comboBoxCanal->currentIndex() != 0)
            ui->comboBoxCanal->setCurrentIndex(0);
    }

    if (infos.generalData.logMessageCount != m_logMessageCount)
    {
        qDebug() << "logMessageCount size:" << infos.generalData.logMessageCount;

        for(int i = m_logMessageCount; i < infos.generalData.logMessageCount; i++)
        {
            qDebug() << "iteration:" << i;
            qDebug() << "size logMessage:" << infos.generalData.logMessages.size();
            qDebug() << infos.generalData.logMessages[i].channel;
            QString htmlOutput = toHtml(infos.generalData.logMessages[i].output);

            switch (infos.generalData.logMessages[i].channel)
            {
            default:
                emit addConsoleLineRequest("<font color=red> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - La chaine demandée n'existe pas</font>");
                break;

            case CHANNELDEBUG:
                emit addConsoleLineRequest("<font color="+QString(DEBUG_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Debug) "+htmlOutput+"</font>");
                break;

            case CHANNELGLOBAL:
                emit addConsoleLineRequest("<font color="+QString(GLOBAL_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELTEAM:
                emit addConsoleLineRequest("<font color="+QString(TEAM_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Equipe) "+htmlOutput+"</font>");
                break;

            case CHANNELGUILD:
                emit addConsoleLineRequest("<font color="+QString(GUILD_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Guilde) "+htmlOutput+"</font>");
                break;

            case CHANNELALLIANCE:
                emit addConsoleLineRequest("<font color="+QString(ALLIANCE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Alliance) "+htmlOutput+"</font>");
                break;

            case CHANNELPARTY:
                emit addConsoleLineRequest("<font color="+QString(PARTY_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Groupe) "+htmlOutput+"</font>");
                break;

            case CHANNELSALES:
                emit addConsoleLineRequest("<font color="+QString(SALES_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Commerce) "+htmlOutput+"</font>");
                break;

            case CHANNELSEEK:
                emit addConsoleLineRequest("<font color="+QString(SEEK_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Recrutement) "+htmlOutput+"</font>");
                break;

            case CHANNELNOOB:
                emit addConsoleLineRequest("<font color="+QString(NOOB_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADMIN:
                emit addConsoleLineRequest("<font color="+QString(ADMIN_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADS:
                emit addConsoleLineRequest("<font color="+QString(ADS_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Communauté FR) "+htmlOutput+"</font>");
                break;

            case CHANNELARENA:
                emit addConsoleLineRequest("<font color="+QString(ARENA_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Kolizéum) "+htmlOutput+"</font>");
                break;

            case CHANNELPRIVATE:
                emit addConsoleLineRequest("<font color="+QString(PRIVATE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELINFO:
                emit addConsoleLineRequest("<font color="+QString(INFO_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELFIGHTLOG:
                emit addConsoleLineRequest("<font color="+QString(FIGHT_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELALERT:
                emit addConsoleLineRequest("<font color="+QString(ERROR_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELACTION:
                emit addConsoleLineRequest("<font color="+QString(ACTION_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELWARN:
                emit addConsoleLineRequest("<font color="+QString(WARN_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELCOMMUNITY:
                emit addConsoleLineRequest("<font color="+QString(COMMUNITY_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELPROMOTION:
                emit addConsoleLineRequest("<font color="+QString(PROMOTION_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;
            }
        }

        m_logMessageCount = infos.generalData.logMessageCount;
    }
}

void ConsoleForm::writeConsole(QString content)
{
    ui->textBrowserConsole->append(content);
}

void ConsoleForm::on_lineEditConsole_returnPressed()
{
    ui->pushButtonSend->click();
}

void ConsoleForm::on_pushButtonSmiley_clicked()
{
    SmileysDialog smileysDialog;
    smileysDialog.setParent(this, Qt::Dialog);
    QList<QString> smileysHappyList;
    QList<QString> smileysSadList;
    QList<QString> smileysOtherList;



    QList<int> listID = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SMILEYS);
    for(int i = 0; i < listID.size(); i++)
    {
        QSharedPointer<SmileyData> smileyData = qSharedPointerCast<SmileyData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SMILEYS, listID.at(i)));
        if(smileyData)
        {
            if(smileyData->getForPlayers() && smileyData->getOrder() && !smileyData->getReferenceId())
            {
                if(smileyData->getCategoryId() == 1)
                    smileysOtherList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));

                if(smileyData->getCategoryId() == 2)
                    smileysHappyList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));

                if(smileyData->getCategoryId() == 3)
                    smileysSadList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));
            }
        }
    }

    smileysDialog.setSmileysHappy(smileysHappyList);
    smileysDialog.setSmileysSad(smileysSadList);
    smileysDialog.setSmileysOther(smileysOtherList);
    if(smileysDialog.exec() == QDialog::Accepted)
    {
        qDebug() << smileysDialog.smiley.toInt();
        m_engine->getFloodModule().sendChatSmiley(m_sender, smileysDialog.smiley.toInt());
    }
}

void ConsoleForm::on_pushButtonSend_clicked()
{
    if (!ui->lineEditConsole->text().isEmpty())
    {
        Channel c;

        switch (ui->comboBoxCanal->currentIndex())
        {
        case 0: c = CHANNELGLOBAL; break;
        case 1:
            c = CHANNELTEAM;
            break;
        case 2:
            c = CHANNELGUILD;
            break;
        case 3:
            c = CHANNELALLIANCE;
            break;
        case 4:
            c = CHANNELPARTY;
            break;
        case 5:
            c = CHANNELPRIVATE;
            break;
        case 6:
            c = CHANNELARENA;
            break;
        case 7:
            c = CHANNELCOMMUNITY;
            break;
        case 8:
            c = CHANNELSALES;
            break;
        case 9:
            c = CHANNELSEEK;
            break;
        }

        QString content = ui->lineEditConsole->text();
        //QRegExp pattern("%[a-z]+%");

        if(content.mid(0, 1) == "/")
        {
            if(content.split("/").last() == "gather")
            {
                if(m_engine->getFarmModule().editResourcesList(m_sender, 38, true)) // Ble
                    qDebug() << "not add";
                else
                    qDebug() << "add";

                if(m_engine->getFarmModule().editResourcesList(m_sender, 75, true)) // Goujon
                    qDebug() << "not add";
                else
                    qDebug() << "add";

                if(m_engine->getFarmModule().editResourcesList(m_sender, 254, true)) // Ortie
                    qDebug() << "not add";
                else
                    qDebug() << "add";

                if(m_engine->getFarmModule().processFarm(m_sender))
                    qDebug() << "je farm";
                else
                    qDebug() << "ya r";
            }
            else if(content.split("/").last() == "fight")
            {

                m_engine->getFightModule().setFightPlacementPosition(m_sender, FightPlacementPosition::NEARFUL);
                m_engine->getFightModule().setFightIA(m_sender, FightIA::FEARFUL);

                QList<RequestedSpell> spells;
                RequestedSpell spell;
                spell.castNb = 2;
                //spell.spellID = 12978; // Attaque Naturelle (Feca)
                //spell.spellID = 13106; // Pression (Iop)
                spell.spellID = 13047; // Flèche magique (Crâ)
                spell.spellCible = SpellCible::ENEMY;
                spells.append(spell);

                m_engine->getFightModule().setRequestedSpells(m_sender, spells);

                RequestedMonsters monsters;
                monsters.mxNbMonsters = 2;
                monsters.groupLevelMax = 100;
                monsters.groupLevelMin = 1;

                MonsterCondition cond;
                cond.id = 3271; // Feu de joie
                cond.monsterInclusion = MonsterInclusion::NONE_EXCEPT;

                monsters.monsterConditions << cond;

                MonsterCondition cond2;
                cond2.id = 3272; // Feu furieux
                cond2.monsterInclusion = MonsterInclusion::ALL_EXCEPT;

                monsters.monsterConditions << cond2;

                m_engine->getFightModule().setRequestedMonsters(m_sender, monsters);
                m_engine->getFightModule().setClosed(m_sender, true);

                if(m_engine->getFightModule().processMonsters(m_sender))
                    qDebug() << "fight ok";
                else
                    qDebug() << "fight ko";
            }
            else if(content.split("/").last() == "pathfinder")
            {
                PathfindingMap *worldpath = new PathfindingMap();
                worldpath->requestPath(PathfindingMap::coordsToMapId(4, 0, 3), PathfindingMap::coordsToMapId(-2, -3, 3), 10, m_sender);
                worldpath->start();
            }
//            else if(content.split("/").last() == "use")
//            {
//                foreach(const StatedElementsInfos e, getData().mapData.statedOnMap)
//                {
//                    qDebug() << e.elementCellId;
//                    if(e.elementCellId == 367)
//                    {
//                        m_engine->getInteractionModule().processUse(m_sender, e.elementId, "");
//                        break;
//                    }
//                }
//            }
        }

        else
        {
            if(c == Channel::CHANNELPRIVATE)
                m_engine->getFloodModule().sendChatMessage(m_sender, content.remove(content.split(" ").at(0)+" "), content.split(" ").at(0));

            else
                m_engine->getFloodModule().sendChatMessage(m_sender, content, c);
        }

        ui->lineEditConsole->setText("");
    }
}

const BotData &ConsoleForm::getData() const
{
    return m_engine->getData(m_sender);
}

void ConsoleForm::on_comboBoxCanal_currentIndexChanged(int index)
{
    if(index == 5)
        ui->lineEditConsole->setPlaceholderText("Nom_Joueur [message]");
    else
        ui->lineEditConsole->setPlaceholderText("");
}
