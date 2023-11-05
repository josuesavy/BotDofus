#ifndef GUILDTAGDATA_H
#define GUILDTAGDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/social/SocialTagData.h"

class GuildTagData : public SocialTagData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GUILDTAGDATA_H