#ifndef ACHIEVEMENTCATEGORYDATA_H
#define ACHIEVEMENTCATEGORYDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class AchievementCategoryData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getParentId() const;
  QString getIcon() const;
  uint getOrder() const;
  QString getColor() const;
  QList<uint> getAchievementIds() const;
  QString getVisibilityCriterion() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_parentId;
  QString m_icon;
  uint m_order;
  QString m_color;
  QList<uint> m_achievementIds;
  QString m_visibilityCriterion;
};

#endif // ACHIEVEMENTCATEGORYDATA_H