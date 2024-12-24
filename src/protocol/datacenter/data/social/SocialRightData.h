#ifndef SOCIALRIGHTDATA_H
#define SOCIALRIGHTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class SocialRightData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  int getGroupId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  int m_groupId;
};

#endif // SOCIALRIGHTDATA_H