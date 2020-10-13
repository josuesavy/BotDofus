#ifndef JOBDATA_H
#define JOBDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class JobData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getIconId() const;
  bool getHasLegendaryCraft() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_iconId;
  bool m_hasLegendaryCraft;
};

#endif // JOBDATA_H