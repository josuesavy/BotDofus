#ifndef EFFECTINSTANCEINTEGERDATA_H
#define EFFECTINSTANCEINTEGERDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/effects/EffectInstanceData.h"

class EffectInstanceIntegerData : public EffectInstanceData
{
public:
  int getValue() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_value;
};

#endif // EFFECTINSTANCEINTEGERDATA_H