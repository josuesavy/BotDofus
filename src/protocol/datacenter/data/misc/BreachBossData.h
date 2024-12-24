#ifndef BREACHBOSSDATA_H
#define BREACHBOSSDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class BreachBossData : public AbstractGameData
{
public:
  int getId() const;
  int getMonsterId() const;
  int getCategory() const;
  QString getApparitionCriterion() const;
  QString getAccessCriterion() const;
  QList<int> getIncompatibleBosses() const;
  uint getRewardId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_monsterId;
  int m_category;
  QString m_apparitionCriterion;
  QString m_accessCriterion;
  QList<int> m_incompatibleBosses;
  uint m_rewardId;
};

#endif // BREACHBOSSDATA_H