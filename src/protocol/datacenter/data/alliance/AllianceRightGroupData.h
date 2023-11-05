#ifndef ALLIANCERIGHTGROUPDATA_H
#define ALLIANCERIGHTGROUPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialRightGroupData.h"

class AllianceRightGroupData : public SocialRightGroupData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCERIGHTGROUPDATA_H