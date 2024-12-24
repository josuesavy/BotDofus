#include "AbuseReasonsData.h"

uint AbuseReasonsData::getAbuseReasonId() const
{
  return m_abuseReasonId;
}

uint AbuseReasonsData::getMask() const
{
  return m_mask;
}

int AbuseReasonsData::getReasonTextId() const
{
  return m_reasonTextId;
}

void AbuseReasonsData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "abuseReasonId")
        m_abuseReasonId = readUInt(field->getValue());
    
    else if(field->getName() == "mask")
        m_mask = readUInt(field->getValue());
    
    else if(field->getName() == "reasonTextId")
        m_reasonTextId = readInt(field->getValue());
    
  }
}

