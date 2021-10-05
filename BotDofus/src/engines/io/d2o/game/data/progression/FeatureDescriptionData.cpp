#include "FeatureDescriptionData.h"

int FeatureDescriptionData::getId() const
{
  return m_id;
}

uint FeatureDescriptionData::getNameId() const
{
  return m_nameId;
}

uint FeatureDescriptionData::getDescriptionId() const
{
  return m_descriptionId;
}

uint FeatureDescriptionData::getPriority() const
{
  return m_priority;
}

uint FeatureDescriptionData::getParentId() const
{
  return m_parentId;
}

QList<int> FeatureDescriptionData::getChildren() const
{
  return m_children;
}

QString FeatureDescriptionData::getCriterion() const
{
  return m_criterion;
}

QString FeatureDescriptionData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString FeatureDescriptionData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void FeatureDescriptionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "priority")
        m_priority = readUInt(field->getValue());
    
    else if(field->getName() == "parentId")
        m_parentId = readUInt(field->getValue());
    
    else if(field->getName() == "children")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_children << readInt(data);
    }
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
  }
}

