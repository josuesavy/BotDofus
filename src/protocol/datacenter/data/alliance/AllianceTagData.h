#ifndef ALLIANCETAGDATA_H
#define ALLIANCETAGDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/social/SocialTagData.h"

class AllianceTagData : public SocialTagData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ALLIANCETAGDATA_H