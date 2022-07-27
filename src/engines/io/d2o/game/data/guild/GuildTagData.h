#ifndef GUILDTAGDATA_H
#define GUILDTAGDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class GuildTagData : public AbstractGameData
{
public:
  int getId() const;
  int getTypeId() const;
  uint getNameId() const;
  int getOrder() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_typeId;
  uint m_nameId;
  int m_order;
};

#endif // GUILDTAGDATA_H