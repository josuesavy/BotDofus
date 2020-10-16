#ifndef QUESTOBJECTIVEFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERDATA_H