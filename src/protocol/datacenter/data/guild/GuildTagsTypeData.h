#ifndef GUILDTAGSTYPEDATA_H
#define GUILDTAGSTYPEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialTagsTypeData.h"

class GuildTagsTypeData : public SocialTagsTypeData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDTAGSTYPEDATA_H