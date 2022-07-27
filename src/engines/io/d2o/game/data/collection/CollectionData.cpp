#include "CollectionData.h"

int CollectionData::getTypeId() const
{
  return m_typeId;
}

int CollectionData::getName() const
{
  return m_name;
}

QString CollectionData::getCriterion() const
{
  return m_criterion;
}

QList<CollectableData> CollectionData::getCollectables() const
{
  return m_collectables;
}

void CollectionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readInt(field->getValue());
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
    else if(field->getName() == "collectables")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_collectables << *qSharedPointerCast<CollectableData>(readObject(data, field)).data();
    }
    
  }
}

