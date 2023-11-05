#include "PopupInformationData.h"

int PopupInformationData::getId() const
{
  return m_id;
}

uint PopupInformationData::getParentId() const
{
  return m_parentId;
}

uint PopupInformationData::getTitleId() const
{
  return m_titleId;
}

uint PopupInformationData::getDescriptionId() const
{
  return m_descriptionId;
}

QString PopupInformationData::getIlluName() const
{
  return m_illuName;
}

QString PopupInformationData::getCriterion() const
{
  return m_criterion;
}

uint PopupInformationData::getCacheType() const
{
  return m_cacheType;
}

bool PopupInformationData::getAutoTrigger() const
{
  return m_autoTrigger;
}

QString PopupInformationData::getTitle() const
{
  return m_I18n->getText(m_titleId);
}

QString PopupInformationData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void PopupInformationData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "parentId")
        m_parentId = readUInt(field->getValue());
    
    else if(field->getName() == "titleId")
        m_titleId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "illuName")
        m_illuName = readUTF(field->getValue());
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
    else if(field->getName() == "cacheType")
        m_cacheType = readUInt(field->getValue());
    
    else if(field->getName() == "autoTrigger")
        m_autoTrigger = readBool(field->getValue());
    
  }
}

