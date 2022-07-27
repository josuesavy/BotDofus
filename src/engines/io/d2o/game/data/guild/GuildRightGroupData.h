#ifndef GUILDRIGHTGROUPDATA_H
#define GUILDRIGHTGROUPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/guild/GuildRightData.h"

class GuildRightGroupData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  QList<GuildRightData> getGuildRights() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  QList<GuildRightData> m_guildRights;
};

#endif // GUILDRIGHTGROUPDATA_H