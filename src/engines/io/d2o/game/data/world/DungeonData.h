#ifndef DUNGEONDATA_H
#define DUNGEONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class DungeonData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOptimalPlayerLevel() const;
  QList<double> getMapIds() const;
  double getEntranceMapId() const;
  double getExitMapId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_optimalPlayerLevel;
  QList<double> m_mapIds;
  double m_entranceMapId;
  double m_exitMapId;
};

#endif // DUNGEONDATA_H