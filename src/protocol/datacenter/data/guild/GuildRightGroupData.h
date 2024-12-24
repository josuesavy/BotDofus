#ifndef GUILDRIGHTGROUPDATA_H
#define GUILDRIGHTGROUPDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialRightGroupData.h"

class GuildRightGroupData : public SocialRightGroupData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDRIGHTGROUPDATA_H