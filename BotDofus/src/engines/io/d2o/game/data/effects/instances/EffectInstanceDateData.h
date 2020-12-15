#ifndef EFFECTINSTANCEDATEDATA_H
#define EFFECTINSTANCEDATEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceDateData : public EffectInstanceData
{
public:
  uint getYear() const;
  uint getMonth() const;
  uint getDay() const;
  uint getHour() const;
  uint getMinute() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_year;
  uint m_month;
  uint m_day;
  uint m_hour;
  uint m_minute;
};

#endif // EFFECTINSTANCEDATEDATA_H