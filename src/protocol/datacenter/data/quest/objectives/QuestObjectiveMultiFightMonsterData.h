#ifndef QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveMultiFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H