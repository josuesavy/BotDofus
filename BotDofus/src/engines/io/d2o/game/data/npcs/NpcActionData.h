#ifndef NPCACTIONDATA_H
#define NPCACTIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class NpcActionData : public AbstractGameData
{
public:
  int getId() const;
  int getRealId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_realId;
  uint m_nameId;
};

#endif // NPCACTIONDATA_H