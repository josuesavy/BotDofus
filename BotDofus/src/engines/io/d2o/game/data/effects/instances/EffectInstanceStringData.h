#ifndef EFFECTINSTANCESTRINGDATA_H
#define EFFECTINSTANCESTRINGDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceStringData : public EffectInstanceData
{
public:
  QString getText() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_text;
};

#endif // EFFECTINSTANCESTRINGDATA_H