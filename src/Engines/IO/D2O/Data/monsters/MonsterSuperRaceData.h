#ifndef MONSTERSUPERRACEDATA_H
#define MONSTERSUPERRACEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MonsterSuperRaceData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // MONSTERSUPERRACEDATA_H