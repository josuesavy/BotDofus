#ifndef ALLIANCETAGSTYPEDATA_H
#define ALLIANCETAGSTYPEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialTagsTypeData.h"

class AllianceTagsTypeData : public SocialTagsTypeData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCETAGSTYPEDATA_H