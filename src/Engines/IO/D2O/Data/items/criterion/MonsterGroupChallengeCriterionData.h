#ifndef MONSTERGROUPCHALLENGECRITERIONDATA_H
#define MONSTERGROUPCHALLENGECRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class MonsterGroupChallengeCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // MONSTERGROUPCHALLENGECRITERIONDATA_H