#ifndef QUESTOBJECTIVEFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERDATA_H