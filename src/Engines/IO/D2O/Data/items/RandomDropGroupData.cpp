#include "RandomDropGroupData.h"

uint RandomDropGroupData::getId() const
{
  return m_id;
}

QString RandomDropGroupData::getName() const
{
  return m_name;
}

QString RandomDropGroupData::getDescription() const
{
  return m_description;
}

QList<RandomDropItemData> RandomDropGroupData::getRandomDropItems() const
{
  return m_randomDropItems;
}

bool RandomDropGroupData::getDisplayChances() const
{
  return m_displayChances;
}

void RandomDropGroupData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "description")
        m_description = readUTF(field->getValue());
    
    else if(field->getName() == "randomDropItems")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_randomDropItems << *qSharedPointerCast<RandomDropItemData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "displayChances")
        m_displayChances = readBool(field->getValue());
    
  }
}

