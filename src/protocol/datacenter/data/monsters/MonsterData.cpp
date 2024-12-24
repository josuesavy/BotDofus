#include "MonsterData.h"

int MonsterData::getId() const
{
  return m_id;
}

uint MonsterData::getNameId() const
{
  return m_nameId;
}

uint MonsterData::getGfxId() const
{
  return m_gfxId;
}

int MonsterData::getRace() const
{
  return m_race;
}

QList<MonsterGradeData> MonsterData::getGrades() const
{
  return m_grades;
}

QString MonsterData::getLook() const
{
  return m_look;
}

bool MonsterData::getUseSummonSlot() const
{
  return m_useSummonSlot;
}

bool MonsterData::getUseBombSlot() const
{
  return m_useBombSlot;
}

bool MonsterData::getCanPlay() const
{
  return m_canPlay;
}

bool MonsterData::getCanTackle() const
{
  return m_canTackle;
}

bool MonsterData::getIsBoss() const
{
  return m_isBoss;
}

QList<MonsterDropData> MonsterData::getDrops() const
{
  return m_drops;
}

QList<MonsterDropData> MonsterData::getTemporisDrops() const
{
  return m_temporisDrops;
}

QList<uint> MonsterData::getSubareas() const
{
  return m_subareas;
}

QList<uint> MonsterData::getSpells() const
{
  return m_spells;
}

QList<QString> MonsterData::getSpellGrades() const
{
  return m_spellGrades;
}

int MonsterData::getFavoriteSubareaId() const
{
  return m_favoriteSubareaId;
}

bool MonsterData::getIsMiniBoss() const
{
  return m_isMiniBoss;
}

bool MonsterData::getIsQuestMonster() const
{
  return m_isQuestMonster;
}

uint MonsterData::getCorrespondingMiniBossId() const
{
  return m_correspondingMiniBossId;
}

double MonsterData::getSpeedAdjust() const
{
  return m_speedAdjust;
}

int MonsterData::getCreatureBoneId() const
{
  return m_creatureBoneId;
}

bool MonsterData::getCanBePushed() const
{
  return m_canBePushed;
}

bool MonsterData::getCanBeCarried() const
{
  return m_canBeCarried;
}

bool MonsterData::getCanUsePortal() const
{
  return m_canUsePortal;
}

bool MonsterData::getCanSwitchPos() const
{
  return m_canSwitchPos;
}

bool MonsterData::getCanSwitchPosOnTarget() const
{
  return m_canSwitchPosOnTarget;
}

bool MonsterData::getFastAnimsFun() const
{
  return m_fastAnimsFun;
}

QList<uint> MonsterData::getIncompatibleChallenges() const
{
  return m_incompatibleChallenges;
}

bool MonsterData::getUseRaceValues() const
{
  return m_useRaceValues;
}

int MonsterData::getAggressiveZoneSize() const
{
  return m_aggressiveZoneSize;
}

int MonsterData::getAggressiveLevelDiff() const
{
  return m_aggressiveLevelDiff;
}

QString MonsterData::getAggressiveImmunityCriterion() const
{
  return m_aggressiveImmunityCriterion;
}

int MonsterData::getAggressiveAttackDelay() const
{
  return m_aggressiveAttackDelay;
}

int MonsterData::getScaleGradeRef() const
{
  return m_scaleGradeRef;
}

QList<QList<double>> MonsterData::getCharacRatios() const
{
  return m_characRatios;
}

QString MonsterData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MonsterData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUInt(field->getValue());
    
    else if(field->getName() == "race")
        m_race = readInt(field->getValue());
    
    else if(field->getName() == "grades")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_grades << *qSharedPointerCast<MonsterGradeData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "look")
        m_look = readUTF(field->getValue());
    
    else if(field->getName() == "useSummonSlot")
        m_useSummonSlot = readBool(field->getValue());
    
    else if(field->getName() == "useBombSlot")
        m_useBombSlot = readBool(field->getValue());
    
    else if(field->getName() == "canPlay")
        m_canPlay = readBool(field->getValue());
    
    else if(field->getName() == "canTackle")
        m_canTackle = readBool(field->getValue());
    
    else if(field->getName() == "isBoss")
        m_isBoss = readBool(field->getValue());
    
    else if(field->getName() == "drops")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_drops << *qSharedPointerCast<MonsterDropData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "temporisDrops")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_temporisDrops << *qSharedPointerCast<MonsterDropData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "subareas")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_subareas << readUInt(data);
    }
    
    else if(field->getName() == "spells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spells << readUInt(data);
    }
    
    else if(field->getName() == "spellGrades")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellGrades << readUTF(data);
    }
    
    else if(field->getName() == "favoriteSubareaId")
        m_favoriteSubareaId = readInt(field->getValue());
    
    else if(field->getName() == "isMiniBoss")
        m_isMiniBoss = readBool(field->getValue());
    
    else if(field->getName() == "isQuestMonster")
        m_isQuestMonster = readBool(field->getValue());
    
    else if(field->getName() == "correspondingMiniBossId")
        m_correspondingMiniBossId = readUInt(field->getValue());
    
    else if(field->getName() == "speedAdjust")
        m_speedAdjust = readDouble(field->getValue());
    
    else if(field->getName() == "creatureBoneId")
        m_creatureBoneId = readInt(field->getValue());
    
    else if(field->getName() == "canBePushed")
        m_canBePushed = readBool(field->getValue());
    
    else if(field->getName() == "canBeCarried")
        m_canBeCarried = readBool(field->getValue());
    
    else if(field->getName() == "canUsePortal")
        m_canUsePortal = readBool(field->getValue());
    
    else if(field->getName() == "canSwitchPos")
        m_canSwitchPos = readBool(field->getValue());
    
    else if(field->getName() == "canSwitchPosOnTarget")
        m_canSwitchPosOnTarget = readBool(field->getValue());
    
    else if(field->getName() == "fastAnimsFun")
        m_fastAnimsFun = readBool(field->getValue());
    
    else if(field->getName() == "incompatibleChallenges")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleChallenges << readUInt(data);
    }
    
    else if(field->getName() == "useRaceValues")
        m_useRaceValues = readBool(field->getValue());
    
    else if(field->getName() == "aggressiveZoneSize")
        m_aggressiveZoneSize = readInt(field->getValue());
    
    else if(field->getName() == "aggressiveLevelDiff")
        m_aggressiveLevelDiff = readInt(field->getValue());
    
    else if(field->getName() == "aggressiveImmunityCriterion")
        m_aggressiveImmunityCriterion = readUTF(field->getValue());
    
    else if(field->getName() == "aggressiveAttackDelay")
        m_aggressiveAttackDelay = readInt(field->getValue());
    
    else if(field->getName() == "scaleGradeRef")
        m_scaleGradeRef = readInt(field->getValue());
    
    else if(field->getName() == "characRatios")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<double> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readDouble(data);
        
        m_characRatios << secondList;
      }
    }
    
  }
}

