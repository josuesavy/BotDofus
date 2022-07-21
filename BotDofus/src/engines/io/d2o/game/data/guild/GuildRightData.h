#ifndef GUILDRIGHTDATA_H
#define GUILDRIGHTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class GuildRightData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  int getGroupId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  int m_groupId;
};

#endif // GUILDRIGHTDATA_H