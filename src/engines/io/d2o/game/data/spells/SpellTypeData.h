#ifndef SPELLTYPEDATA_H
#define SPELLTYPEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SpellTypeData : public AbstractGameData
{
public:
  int getId() const;
  uint getLongNameId() const;
  uint getShortNameId() const;
  QString getLongName() const;
  QString getShortName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_longNameId;
  uint m_shortNameId;
};

#endif // SPELLTYPEDATA_H