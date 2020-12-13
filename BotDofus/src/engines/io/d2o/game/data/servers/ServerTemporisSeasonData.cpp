#include "ServerTemporisSeasonData.h"

int ServerTemporisSeasonData::getUid() const
{
  return m_uid;
}

uint ServerTemporisSeasonData::getSeasonNumber() const
{
  return m_seasonNumber;
}

QString ServerTemporisSeasonData::getInformation() const
{
  return m_information;
}

double ServerTemporisSeasonData::getBeginning() const
{
  return m_beginning;
}

double ServerTemporisSeasonData::getClosure() const
{
  return m_closure;
}

void ServerTemporisSeasonData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "uid")
        m_uid = readInt(field->getValue());
    
    else if(field->getName() == "seasonNumber")
        m_seasonNumber = readUInt(field->getValue());
    
    else if(field->getName() == "information")
        m_information = readUTF(field->getValue());
    
    else if(field->getName() == "beginning")
        m_beginning = readDouble(field->getValue());
    
    else if(field->getName() == "closure")
        m_closure = readDouble(field->getValue());
    
  }
}

