#ifndef EFFECTINSTANCECREATUREDATA_H
#define EFFECTINSTANCECREATUREDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceCreatureData : public EffectInstanceData
{
public:
  uint getMonsterFamilyId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_monsterFamilyId;
};

#endif // EFFECTINSTANCECREATUREDATA_H