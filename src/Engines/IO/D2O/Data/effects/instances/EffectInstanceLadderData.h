#ifndef EFFECTINSTANCELADDERDATA_H
#define EFFECTINSTANCELADDERDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceCreatureData.h"

class EffectInstanceLadderData : public EffectInstanceCreatureData
{
public:
  uint getMonsterCount() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_monsterCount;
};

#endif // EFFECTINSTANCELADDERDATA_H