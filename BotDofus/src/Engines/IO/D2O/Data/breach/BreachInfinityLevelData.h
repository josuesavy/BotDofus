#ifndef BREACHINFINITYLEVELDATA_H
#define BREACHINFINITYLEVELDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class BreachInfinityLevelData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getLevel() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_level;
};

#endif // BREACHINFINITYLEVELDATA_H