#ifndef MONSTERRACEDATA_H
#define MONSTERRACEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class MonsterRaceData : public AbstractGameData
{
public:
  int getId() const;
  int getSuperRaceId() const;
  uint getNameId() const;
  QList<uint> getMonsters() const;
  int getAggressiveZoneSize() const;
  int getAggressiveLevelDiff() const;
  QString getAggressiveImmunityCriterion() const;
  int getAggressiveAttackDelay() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_superRaceId;
  uint m_nameId;
  QList<uint> m_monsters;
  int m_aggressiveZoneSize;
  int m_aggressiveLevelDiff;
  QString m_aggressiveImmunityCriterion;
  int m_aggressiveAttackDelay;
};

#endif // MONSTERRACEDATA_H