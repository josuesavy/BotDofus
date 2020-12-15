#ifndef QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveData.h"

class QuestObjectiveMultiFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEMULTIFIGHTMONSTERDATA_H