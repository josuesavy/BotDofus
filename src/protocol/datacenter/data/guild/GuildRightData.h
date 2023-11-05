#ifndef GUILDRIGHTDATA_H
#define GUILDRIGHTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialRightData.h"

class GuildRightData : public SocialRightData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDRIGHTDATA_H