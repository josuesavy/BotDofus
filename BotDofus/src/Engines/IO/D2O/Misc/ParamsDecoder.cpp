#include "ParamsDecoder.h"

QString ParamsDecoder::applyParams(QString txt, QStringList params, QString replace)
{
    QChar c;
    bool lectureType = false;
    bool lectureId= false;
    QString type;
    QString id;
    QString s;

    for(int i = 0; i < txt.size(); i++)
    {
        c = txt.at(i);

        if(c == '$')
            lectureType = true;

        else if(c == replace)
        {
            if(i + 1 < txt.size() && txt.at(i+1) == replace)
            {
                lectureId = false;
                lectureType = false;
                i++;
            }

            else
            {
                lectureType = false;
                lectureId = true;
            }
        }

        if(lectureType)
            type += c;

        else if(lectureId)
        {
            if(c == replace)
            {
                if(!id.isEmpty())
                {
                    s += processReplace(type,id,params);
                    type.clear();
                    id = c;
                }

                else
                    id = c;

                id = c;
            }

            else if(c.isDigit())
            {
                id += c;

                if(i + 1 == txt.size())
                {
                    lectureId = false;
                    s = s + processReplace(type,id,params);
                    type.clear();
                    id.clear();
                }
            }

            else
            {
                lectureId = false;
                s = s + processReplace(type,id,params);
                type.clear();
                id.clear();
                s += c;
            }

        }

        else
        {
            if(!id.isEmpty())
            {
                s = s + processReplace(type,id,params);
                type.clear();
                id.clear();
            }

            s = s + c;
        }

    }

    return s;
}

QString ParamsDecoder::processReplace(QString type, QString id, QStringList params)
{
    int nid = 0;
    QString newString;

    nid = toInt(id.mid(1)) -1;

    if(type.isEmpty())
        newString = params[nid];

    else
    {
        if(type == "$item")
        {
            QSharedPointer<ItemData> item = qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, toInt(params[nid])));
            newString =  item->getName();
        }

        else if(type == "$itemType")
        {
            QSharedPointer<ItemTypeData> itemType = qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, toInt(params[nid])));
            newString = itemType->getName();
        }

        else if(type == "$quantity")
            newString = params[nid];

        else if(type == "$job")
        {
            QSharedPointer<JobData> job = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, toInt(params[nid])));
            newString = job->getName();
        }

        else if(type == "$quest")
        {
            QSharedPointer<QuestData> quest = qSharedPointerCast<QuestData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::QUESTS, toInt(params[nid])));
            newString = quest->getName();
        }

        else if(type == "$achievement")
        {
            QSharedPointer<AchievementData> achievement = qSharedPointerCast<AchievementData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ACHIEVEMENTS, toInt(params[nid])));
            newString = achievement->getName();
        }

        else if(type == "$title")
        {
            QSharedPointer<TitleData> title = qSharedPointerCast<TitleData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::TITLES, toInt(params[nid])));
            if(!title->getNameFemale().isEmpty())
                newString = title->getNameFemale();

            else if(!title->getNameMale().isEmpty())
                newString = title->getNameMale();
        }

        else if(type == "$ornament")
        {
            QSharedPointer<OrnamentData> ornament = qSharedPointerCast<OrnamentData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ORNAMENTS, toInt(params[nid])));
            newString = ornament->getName();
        }

        else if(type == "$spell")
        {
            QSharedPointer<SpellData> spell = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, toInt(params[nid])));
            newString = spell->getName();
        }

        else if(type == "$spellState")
        {
            QSharedPointer<SpellStateData> spellState = qSharedPointerCast<SpellStateData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLSTATES, toInt(params[nid])));
            newString = spellState->getName();
        }

        else if(type == "$breed")
        {
            QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, toInt(params[nid])));
            newString = breed->getShortName();
        }

        else if(type == "$area")
        {
            QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, toInt(params[nid])));
            newString = area->getName();
        }

        else if(type == "$subarea")
        {
            QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, toInt(params[nid])));
            newString = subArea->getName();
        }

        else if(type == "$map")
        {
            QSharedPointer<MapPositionData> map = qSharedPointerCast<MapPositionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MAPPOSITIONS, toInt(params[nid])));
            newString = "["+QString::number(map->getPosX())+","+QString::number(map->getPosY())+"]";
        }

        else if(type == "$emote")
        {
            QSharedPointer<EmoticonData> emote = qSharedPointerCast<EmoticonData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EMOTICONS, toInt(params[nid])));
            newString = emote->getName();
        }

        else if(type == "$monster")
        {
            QSharedPointer<MonsterData> monster = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, toInt(params[nid])));
            newString = monster->getName();
        }

        else if(type == "$monsterRace")
        {
            QSharedPointer<MonsterRaceData> monsterRace = qSharedPointerCast<MonsterRaceData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERRACES, toInt(params[nid])));
            newString = monsterRace->getName();
        }

        else if(type == "$monsterSuperRace")
        {
            QSharedPointer<MonsterSuperRaceData> monsterSuperRace = qSharedPointerCast<MonsterSuperRaceData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERSUPERRACES, toInt(params[nid])));
            newString = monsterSuperRace->getName();
        }

        else if(type == "$challenge")
        {
            QSharedPointer<ChallengeData> challenge = qSharedPointerCast<ChallengeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHALLENGE, toInt(params[nid])));
            newString = challenge->getName();
        }

        else if(type == "$alignment")
        {
            QSharedPointer<AlignmentSideData> alignmentSide = qSharedPointerCast<AlignmentSideData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ALIGNMENTSIDES, toInt(params[nid])));
            newString = alignmentSide->getName();
        }

        else if(type == "$stat")
            newString = D2OManagerSingleton::get()->m_I18n->getText("ui.item.characteristics").split(",")[params[nid].toInt()];

        else if(type == "$dungeon")
        {
            QSharedPointer<DungeonData> dungeon = qSharedPointerCast<DungeonData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::DUNGEONS, toInt(params[nid])));
            newString = dungeon->getName();
        }

        else if(type == "$time")
        {
            long long timeToDisplay = params[nid].toInt() * 1000 - QDateTime::currentDateTime().toMSecsSinceEpoch();

            if(timeToDisplay < 0)
                timeToDisplay = 0;

            newString = QDateTime::fromMSecsSinceEpoch(timeToDisplay).toString("hh:mm:ss");
        }

        else if(type == "$date")
            newString = QDateTime::fromMSecsSinceEpoch(toInt(params[nid]) * 1000).toString("dd/mm/yy hh:mm");

        else if(type == "$companion" || type == "$sidekick")
        {
            QSharedPointer<CompanionData> companion = qSharedPointerCast<CompanionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::COMPANIONS, toInt(params[nid])));
            newString = companion->getName();
        }

        else if(type == "$breach")
            newString = D2OManagerSingleton::get()->getI18N()->getText("ui.breach.roomNumber").replace("%1", params[nid]) + ", " + D2OManagerSingleton::get()->getI18N()->getText("ui.breach.floor").replace("%1", params[nid]);
    }

    return newString;
}
