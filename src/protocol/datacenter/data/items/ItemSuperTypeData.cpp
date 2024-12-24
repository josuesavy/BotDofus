#include "ItemSuperTypeData.h"

int ItemSuperTypeData::getId() const
{
  return m_id;
}

QList<int> ItemSuperTypeData::getPossiblePositions() const
{
  return m_possiblePositions;
}

void ItemSuperTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "possiblePositions")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_possiblePositions << readInt(data);
    }
    
  }
}

