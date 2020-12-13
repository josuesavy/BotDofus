#ifndef EVOLUTIVEEFFECTDATA_H
#define EVOLUTIVEEFFECTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class EvolutiveEffectData : public AbstractGameData
{
public:
  int getId() const;
  int getActionId() const;
  int getTargetId() const;
  QList<QList<double>> getProgressionPerLevelRange() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_actionId;
  int m_targetId;
  QList<QList<double>> m_progressionPerLevelRange;
};

#endif // EVOLUTIVEEFFECTDATA_H