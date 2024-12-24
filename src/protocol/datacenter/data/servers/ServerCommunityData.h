#ifndef SERVERCOMMUNITYDATA_H
#define SERVERCOMMUNITYDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ServerCommunityData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getShortId() const;
  QList<QString> getDefaultCountries() const;
  QList<int> getSupportedLangIds() const;
  int getNamingRulePlayerNameId() const;
  int getNamingRuleGuildNameId() const;
  int getNamingRuleAllianceNameId() const;
  int getNamingRuleAllianceTagId() const;
  int getNamingRulePartyNameId() const;
  int getNamingRuleMountNameId() const;
  int getNamingRuleNameGeneratorId() const;
  int getNamingRuleAdminId() const;
  int getNamingRuleModoId() const;
  int getNamingRulePresetNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  QString m_shortId;
  QList<QString> m_defaultCountries;
  QList<int> m_supportedLangIds;
  int m_namingRulePlayerNameId;
  int m_namingRuleGuildNameId;
  int m_namingRuleAllianceNameId;
  int m_namingRuleAllianceTagId;
  int m_namingRulePartyNameId;
  int m_namingRuleMountNameId;
  int m_namingRuleNameGeneratorId;
  int m_namingRuleAdminId;
  int m_namingRuleModoId;
  int m_namingRulePresetNameId;
};

#endif // SERVERCOMMUNITYDATA_H