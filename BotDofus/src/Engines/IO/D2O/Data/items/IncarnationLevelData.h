#ifndef INCARNATIONLEVELDATA_H
#define INCARNATIONLEVELDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class IncarnationLevelData : public AbstractGameData
{
public:
  int getId() const;
  int getIncarnationId() const;
  int getLevel() const;
  uint getRequiredXp() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_incarnationId;
  int m_level;
  uint m_requiredXp;
};

#endif // INCARNATIONLEVELDATA_H