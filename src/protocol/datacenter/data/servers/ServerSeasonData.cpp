#include "ServerSeasonData.h"

int ServerSeasonData::getUid() const
{
  return m_uid;
}

uint ServerSeasonData::getSeasonNumber() const
{
  return m_seasonNumber;
}

QString ServerSeasonData::getInformation() const
{
  return m_information;
}

double ServerSeasonData::getBeginning() const
{
  return m_beginning;
}

double ServerSeasonData::getClosure() const
{
  return m_closure;
}

double ServerSeasonData::getResetDate() const
{
  return m_resetDate;
}

uint ServerSeasonData::getFlagObjectId() const
{
  return m_flagObjectId;
}

void ServerSeasonData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "resetDate")
        m_resetDate = readDouble(field->getValue());
    
    else if(field->getName() == "flagObjectId")
        m_flagObjectId = readUInt(field->getValue());
    
  }
}

