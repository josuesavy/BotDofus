#include "ModsterData.h"

int ModsterData::getId() const
{
  return m_id;
}

int ModsterData::getSpellIdKroma() const
{
  return m_spellIdKroma;
}

int ModsterData::getItemId() const
{
  return m_itemId;
}

int ModsterData::getItemIdKroma() const
{
  return m_itemIdKroma;
}

int ModsterData::getModsterId() const
{
  return m_modsterId;
}

int ModsterData::getOrder() const
{
  return m_order;
}

QList<int> ModsterData::getParentsModsterId() const
{
  return m_parentsModsterId;
}

QList<int> ModsterData::getModsterActiveSpells() const
{
  return m_modsterActiveSpells;
}

QList<int> ModsterData::getModsterPassiveSpells() const
{
  return m_modsterPassiveSpells;
}

QList<int> ModsterData::getModsterHiddenAchievements() const
{
  return m_modsterHiddenAchievements;
}

QList<int> ModsterData::getModsterAchievements() const
{
  return m_modsterAchievements;
}

QList<int> ModsterData::getKromaHiddenAchievements() const
{
  return m_kromaHiddenAchievements;
}

QList<int> ModsterData::getKromaAchievements() const
{
  return m_kromaAchievements;
}

void ModsterData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "spellIdKroma")
        m_spellIdKroma = readInt(field->getValue());
    
    else if(field->getName() == "itemId")
        m_itemId = readInt(field->getValue());
    
    else if(field->getName() == "itemIdKroma")
        m_itemIdKroma = readInt(field->getValue());
    
    else if(field->getName() == "modsterId")
        m_modsterId = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "parentsModsterId")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_parentsModsterId << readInt(data);
    }
    
    else if(field->getName() == "modsterActiveSpells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_modsterActiveSpells << readInt(data);
    }
    
    else if(field->getName() == "modsterPassiveSpells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_modsterPassiveSpells << readInt(data);
    }
    
    else if(field->getName() == "modsterHiddenAchievements")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_modsterHiddenAchievements << readInt(data);
    }
    
    else if(field->getName() == "modsterAchievements")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_modsterAchievements << readInt(data);
    }
    
    else if(field->getName() == "kromaHiddenAchievements")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_kromaHiddenAchievements << readInt(data);
    }
    
    else if(field->getName() == "kromaAchievements")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_kromaAchievements << readInt(data);
    }
    
  }
}

