#ifndef ALLIANCERIGHTDATA_H
#define ALLIANCERIGHTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialRightData.h"

class AllianceRightData : public SocialRightData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCERIGHTDATA_H