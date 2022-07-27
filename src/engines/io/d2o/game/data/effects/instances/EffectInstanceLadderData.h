#ifndef EFFECTINSTANCELADDERDATA_H
#define EFFECTINSTANCELADDERDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceCreatureData.h"

class EffectInstanceLadderData : public EffectInstanceCreatureData
{
public:
  uint getMonsterCount() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_monsterCount;
};

#endif // EFFECTINSTANCELADDERDATA_H