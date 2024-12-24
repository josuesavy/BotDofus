#ifndef ALLIANCERIGHTGROUPDATA_H
#define ALLIANCERIGHTGROUPDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialRightGroupData.h"

class AllianceRightGroupData : public SocialRightGroupData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCERIGHTGROUPDATA_H