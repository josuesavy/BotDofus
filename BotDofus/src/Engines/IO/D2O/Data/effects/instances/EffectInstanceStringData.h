#ifndef EFFECTINSTANCESTRINGDATA_H
#define EFFECTINSTANCESTRINGDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/effects/EffectInstanceData.h"

class EffectInstanceStringData : public EffectInstanceData
{
public:
  QString getText() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_text;
};

#endif // EFFECTINSTANCESTRINGDATA_H