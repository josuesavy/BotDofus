#include "OptionalFeatureData.h"

int OptionalFeatureData::getId() const
{
  return m_id;
}

QString OptionalFeatureData::getKeyword() const
{
  return m_keyword;
}

bool OptionalFeatureData::getIsClient() const
{
  return m_isClient;
}

bool OptionalFeatureData::getIsServer() const
{
  return m_isServer;
}

bool OptionalFeatureData::getIsActivationOnLaunch() const
{
  return m_isActivationOnLaunch;
}

bool OptionalFeatureData::getIsActivationOnServerConnection() const
{
  return m_isActivationOnServerConnection;
}

QString OptionalFeatureData::getActivationCriterions() const
{
  return m_activationCriterions;
}

void OptionalFeatureData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "keyword")
        m_keyword = readUTF(field->getValue());
    
    else if(field->getName() == "isClient")
        m_isClient = readBool(field->getValue());
    
    else if(field->getName() == "isServer")
        m_isServer = readBool(field->getValue());
    
    else if(field->getName() == "isActivationOnLaunch")
        m_isActivationOnLaunch = readBool(field->getValue());
    
    else if(field->getName() == "isActivationOnServerConnection")
        m_isActivationOnServerConnection = readBool(field->getValue());
    
    else if(field->getName() == "activationCriterions")
        m_activationCriterions = readUTF(field->getValue());
    
  }
}

