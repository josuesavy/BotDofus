#ifndef SOCIALRIGHTGROUPDATA_H
#define SOCIALRIGHTGROUPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SocialRightGroupData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
};

#endif // SOCIALRIGHTGROUPDATA_H