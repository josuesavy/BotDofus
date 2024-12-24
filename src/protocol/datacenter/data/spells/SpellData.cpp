#include "SpellData.h"

int SpellData::getId() const
{
  return m_id;
}

uint SpellData::getNameId() const
{
  return m_nameId;
}

uint SpellData::getDescriptionId() const
{
  return m_descriptionId;
}

uint SpellData::getTypeId() const
{
  return m_typeId;
}

uint SpellData::getOrder() const
{
  return m_order;
}

QList<BoundScriptUsageDataData> SpellData::getBoundScriptUsageData() const
{
  return m_boundScriptUsageData;
}

QList<BoundScriptUsageDataData> SpellData::getCriticalHitBoundScriptUsageData() const
{
  return m_criticalHitBoundScriptUsageData;
}

uint SpellData::getIconId() const
{
  return m_iconId;
}

QList<uint> SpellData::getSpellLevels() const
{
  return m_spellLevels;
}

bool SpellData::getUseParamCache() const
{
  return m_useParamCache;
}

bool SpellData::getVerboseCast() const
{
  return m_verboseCast;
}

QString SpellData::getDefaultPreviewZone() const
{
  return m_defaultPreviewZone;
}

bool SpellData::getBypassSummoningLimit() const
{
  return m_bypassSummoningLimit;
}

bool SpellData::getCanAlwaysTriggerSpells() const
{
  return m_canAlwaysTriggerSpells;
}

QString SpellData::getAdminName() const
{
  return m_adminName;
}

bool SpellData::getHideCastConditions() const
{
  return m_hideCastConditions;
}

QString SpellData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString SpellData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void SpellData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "boundScriptUsageData")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_boundScriptUsageData << *qSharedPointerCast<BoundScriptUsageDataData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "criticalHitBoundScriptUsageData")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_criticalHitBoundScriptUsageData << *qSharedPointerCast<BoundScriptUsageDataData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "spellLevels")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellLevels << readUInt(data);
    }
    
    else if(field->getName() == "useParamCache")
        m_useParamCache = readBool(field->getValue());
    
    else if(field->getName() == "verboseCast")
        m_verboseCast = readBool(field->getValue());
    
    else if(field->getName() == "defaultPreviewZone")
        m_defaultPreviewZone = readUTF(field->getValue());
    
    else if(field->getName() == "bypassSummoningLimit")
        m_bypassSummoningLimit = readBool(field->getValue());
    
    else if(field->getName() == "canAlwaysTriggerSpells")
        m_canAlwaysTriggerSpells = readBool(field->getValue());
    
    else if(field->getName() == "adminName")
        m_adminName = readUTF(field->getValue());
    
    else if(field->getName() == "hideCastConditions")
        m_hideCastConditions = readBool(field->getValue());
    
  }
}

