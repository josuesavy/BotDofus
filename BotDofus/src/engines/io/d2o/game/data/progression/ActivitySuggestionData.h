#ifndef ACTIVITYSUGGESTIONDATA_H
#define ACTIVITYSUGGESTIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ActivitySuggestionData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  int getCategoryId() const;
  uint getLevel() const;
  double getMapId() const;
  bool getIsLarge() const;
  double getStartDate() const;
  double getEndDate() const;
  QString getIcon() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  int m_categoryId;
  uint m_level;
  double m_mapId;
  bool m_isLarge;
  double m_startDate;
  double m_endDate;
  QString m_icon;
};

#endif // ACTIVITYSUGGESTIONDATA_H