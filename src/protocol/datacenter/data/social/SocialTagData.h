#ifndef SOCIALTAGDATA_H
#define SOCIALTAGDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SocialTagData : public AbstractGameData
{
public:
  int getId() const;
  int getTypeId() const;
  uint getNameId() const;
  int getOrder() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_typeId;
  uint m_nameId;
  int m_order;
};

#endif // SOCIALTAGDATA_H