#ifndef ACHIEVEMENTOBJECTIVEDATA_H
#define ACHIEVEMENTOBJECTIVEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AchievementObjectiveData : public AbstractGameData
{
public:
  uint getId() const;
  uint getAchievementId() const;
  uint getOrder() const;
  uint getNameId() const;
  QString getCriterion() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_achievementId;
  uint m_order;
  uint m_nameId;
  QString m_criterion;
};

#endif // ACHIEVEMENTOBJECTIVEDATA_H