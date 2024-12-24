#ifndef GUILDRIGHTDATA_H
#define GUILDRIGHTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialRightData.h"

class GuildRightData : public SocialRightData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDRIGHTDATA_H