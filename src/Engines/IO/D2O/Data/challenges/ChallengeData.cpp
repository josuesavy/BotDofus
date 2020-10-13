#include "ChallengeData.h"

int ChallengeData::getId() const
{
  return m_id;
}

uint ChallengeData::getNameId() const
{
  return m_nameId;
}

uint ChallengeData::getDescriptionId() const
{
  return m_descriptionId;
}

QList<uint> ChallengeData::getIncompatibleChallenges() const
{
  return m_incompatibleChallenges;
}

int ChallengeData::getCategoryId() const
{
  return m_categoryId;
}

uint ChallengeData::getIconId() const
{
  return m_iconId;
}

QString ChallengeData::getActivationCriterion() const
{
  return m_activationCriterion;
}

QString ChallengeData::getCompletionCriterion() const
{
  return m_completionCriterion;
}

QString ChallengeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ChallengeData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ChallengeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "incompatibleChallenges")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleChallenges << readUInt(data);
    }
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "activationCriterion")
        m_activationCriterion = readUTF(field->getValue());
    
    else if(field->getName() == "completionCriterion")
        m_completionCriterion = readUTF(field->getValue());
    
  }
}

