#include "LegendaryPowerCategoryData.h"

int LegendaryPowerCategoryData::getId() const
{
  return m_id;
}

QString LegendaryPowerCategoryData::getCategoryName() const
{
  return m_categoryName;
}

bool LegendaryPowerCategoryData::getCategoryOverridable() const
{
  return m_categoryOverridable;
}

QList<int> LegendaryPowerCategoryData::getCategorySpells() const
{
  return m_categorySpells;
}

void LegendaryPowerCategoryData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "categoryName")
        m_categoryName = readUTF(field->getValue());
    
    else if(field->getName() == "categoryOverridable")
        m_categoryOverridable = readBool(field->getValue());
    
    else if(field->getName() == "categorySpells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_categorySpells << readInt(data);
    }
    
  }
}

