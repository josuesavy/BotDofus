#include "CreatureBoneOverrideData.h"

int CreatureBoneOverrideData::getBoneId() const
{
  return m_boneId;
}

int CreatureBoneOverrideData::getCreatureBoneId() const
{
  return m_creatureBoneId;
}

void CreatureBoneOverrideData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "boneId")
        m_boneId = readInt(field->getValue());
    
    else if(field->getName() == "creatureBoneId")
        m_creatureBoneId = readInt(field->getValue());
    
  }
}

