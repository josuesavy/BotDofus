#ifndef QUESTOBJECTIVEFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERDATA_H