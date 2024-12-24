#ifndef EFFECTINSTANCEDURATIONDATA_H
#define EFFECTINSTANCEDURATIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/effects/EffectInstanceData.h"

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