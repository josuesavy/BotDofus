#ifndef ALLIANCETAGSTYPEDATA_H
#define ALLIANCETAGSTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialTagsTypeData.h"

class AllianceTagsTypeData : public SocialTagsTypeData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCETAGSTYPEDATA_H