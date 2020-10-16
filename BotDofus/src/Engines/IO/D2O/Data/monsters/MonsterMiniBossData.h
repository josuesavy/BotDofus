#ifndef MONSTERMINIBOSSDATA_H
#define MONSTERMINIBOSSDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MonsterMiniBossData : public AbstractGameData
{
public:
  int getId() const;
  int getMonsterReplacingId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_monsterReplacingId;
};

#endif // MONSTERMINIBOSSDATA_H