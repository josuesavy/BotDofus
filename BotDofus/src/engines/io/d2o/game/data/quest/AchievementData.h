#ifndef ACHIEVEMENTDATA_H
#define ACHIEVEMENTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class AchievementData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getCategoryId() const;
  uint getDescriptionId() const;
  uint getIconId() const;
  uint getPoints() const;
  uint getLevel() const;
  uint getOrder() const;
  bool getAccountLinked() const;
  QList<int> getObjectiveIds() const;
  QList<int> getRewardIds() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_categoryId;
  uint m_descriptionId;
  uint m_iconId;
  uint m_points;
  uint m_level;
  uint m_order;
  bool m_accountLinked;
  QList<int> m_objectiveIds;
  QList<int> m_rewardIds;
};

#endif // ACHIEVEMENTDATA_H