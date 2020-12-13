#include "IncarnationData.h"

uint IncarnationData::getId() const
{
  return m_id;
}

uint IncarnationData::getMaleBoneId() const
{
  return m_maleBoneId;
}

uint IncarnationData::getFemaleBoneId() const
{
  return m_femaleBoneId;
}

QString IncarnationData::getLookMale() const
{
  return m_lookMale;
}

QString IncarnationData::getLookFemale() const
{
  return m_lookFemale;
}

void IncarnationData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "maleBoneId")
        m_maleBoneId = readUInt(field->getValue());
    
    else if(field->getName() == "femaleBoneId")
        m_femaleBoneId = readUInt(field->getValue());
    
    else if(field->getName() == "lookMale")
        m_lookMale = readUTF(field->getValue());
    
    else if(field->getName() == "lookFemale")
        m_lookFemale = readUTF(field->getValue());
    
  }
}

