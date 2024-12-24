#ifndef GUILDRANKDATA_H
#define GUILDRANKDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class GuildRankData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  bool getIsModifiable() const;
  uint getGfxId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  bool m_isModifiable;
  uint m_gfxId;
};

#endif // GUILDRANKDATA_H