#ifndef EFFECTINSTANCEMINMAXDATA_H
#define EFFECTINSTANCEMINMAXDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceMinMaxData : public EffectInstanceData
{
public:
  uint getMin() const;
  uint getMax() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_min;
  uint m_max;
};

#endif // EFFECTINSTANCEMINMAXDATA_H