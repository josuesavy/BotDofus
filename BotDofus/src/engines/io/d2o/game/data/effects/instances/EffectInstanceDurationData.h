#ifndef EFFECTINSTANCEDURATIONDATA_H
#define EFFECTINSTANCEDURATIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceDurationData : public EffectInstanceData
{
public:
  uint getDays() const;
  uint getHours() const;
  uint getMinutes() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_days;
  uint m_hours;
  uint m_minutes;
};

#endif // EFFECTINSTANCEDURATIONDATA_H