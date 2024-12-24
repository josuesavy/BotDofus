#ifndef SOCIALRIGHTGROUPDATA_H
#define SOCIALRIGHTGROUPDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialRightData.h"

class SocialRightGroupData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  QList<SocialRightData> getRights() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  QList<SocialRightData> m_rights;
};

#endif // SOCIALRIGHTGROUPDATA_H