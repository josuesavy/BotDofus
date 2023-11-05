#ifndef EFFECTINSTANCEMOUNTDATA_H
#define EFFECTINSTANCEMOUNTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class EffectInstanceMountData : public EffectInstanceData
{
public:
  double getId() const;
  double getExpirationDate() const;
  uint getModel() const;
  QString getName() const;
  QString getOwner() const;
  uint getLevel() const;
  bool getSex() const;
  bool getIsRideable() const;
  bool getIsFeconded() const;
  bool getIsFecondationReady() const;
  int getReproductionCount() const;
  uint getReproductionCountMax() const;
  QList<uint> getCapacities() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  double m_id;
  double m_expirationDate;
  uint m_model;
  QString m_name;
  QString m_owner;
  uint m_level;
  bool m_sex;
  bool m_isRideable;
  bool m_isFeconded;
  bool m_isFecondationReady;
  int m_reproductionCount;
  uint m_reproductionCountMax;
  QList<uint> m_capacities;
};

#endif // EFFECTINSTANCEMOUNTDATA_H