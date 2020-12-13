#ifndef ITEMSETDATA_H
#define ITEMSETDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class ItemSetData : public AbstractGameData
{
public:
  uint getId() const;
  QList<uint> getItems() const;
  uint getNameId() const;
  QList<QList<EffectInstanceData>> getEffects() const;
  bool getBonusIsSecret() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  QList<uint> m_items;
  uint m_nameId;
  QList<QList<EffectInstanceData>> m_effects;
  bool m_bonusIsSecret;
};

#endif // ITEMSETDATA_H