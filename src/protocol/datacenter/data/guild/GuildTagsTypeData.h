#ifndef GUILDTAGSTYPEDATA_H
#define GUILDTAGSTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialTagsTypeData.h"

class GuildTagsTypeData : public SocialTagsTypeData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDTAGSTYPEDATA_H