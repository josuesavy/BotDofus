#include "ServerCommunityData.h"

int ServerCommunityData::getId() const
{
  return m_id;
}

uint ServerCommunityData::getNameId() const
{
  return m_nameId;
}

QString ServerCommunityData::getShortId() const
{
  return m_shortId;
}

QList<QString> ServerCommunityData::getDefaultCountries() const
{
  return m_defaultCountries;
}

QList<int> ServerCommunityData::getSupportedLangIds() const
{
  return m_supportedLangIds;
}

int ServerCommunityData::getNamingRulePlayerNameId() const
{
  return m_namingRulePlayerNameId;
}

int ServerCommunityData::getNamingRuleGuildNameId() const
{
  return m_namingRuleGuildNameId;
}

int ServerCommunityData::getNamingRuleAllianceNameId() const
{
  return m_namingRuleAllianceNameId;
}

int ServerCommunityData::getNamingRuleAllianceTagId() const
{
  return m_namingRuleAllianceTagId;
}

int ServerCommunityData::getNamingRulePartyNameId() const
{
  return m_namingRulePartyNameId;
}

int ServerCommunityData::getNamingRuleMountNameId() const
{
  return m_namingRuleMountNameId;
}

int ServerCommunityData::getNamingRuleNameGeneratorId() const
{
  return m_namingRuleNameGeneratorId;
}

int ServerCommunityData::getNamingRuleAdminId() const
{
  return m_namingRuleAdminId;
}

int ServerCommunityData::getNamingRuleModoId() const
{
  return m_namingRuleModoId;
}

int ServerCommunityData::getNamingRulePresetNameId() const
{
  return m_namingRulePresetNameId;
}

QString ServerCommunityData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ServerCommunityData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "shortId")
        m_shortId = readUTF(field->getValue());
    
    else if(field->getName() == "defaultCountries")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_defaultCountries << readUTF(data);
    }
    
    else if(field->getName() == "supportedLangIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_supportedLangIds << readInt(data);
    }
    
    else if(field->getName() == "namingRulePlayerNameId")
        m_namingRulePlayerNameId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleGuildNameId")
        m_namingRuleGuildNameId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleAllianceNameId")
        m_namingRuleAllianceNameId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleAllianceTagId")
        m_namingRuleAllianceTagId = readInt(field->getValue());
    
    else if(field->getName() == "namingRulePartyNameId")
        m_namingRulePartyNameId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleMountNameId")
        m_namingRuleMountNameId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleNameGeneratorId")
        m_namingRuleNameGeneratorId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleAdminId")
        m_namingRuleAdminId = readInt(field->getValue());
    
    else if(field->getName() == "namingRuleModoId")
        m_namingRuleModoId = readInt(field->getValue());
    
    else if(field->getName() == "namingRulePresetNameId")
        m_namingRulePresetNameId = readInt(field->getValue());
    
  }
}

