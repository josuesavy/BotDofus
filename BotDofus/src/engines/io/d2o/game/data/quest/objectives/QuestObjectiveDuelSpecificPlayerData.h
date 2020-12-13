#ifndef QUESTOBJECTIVEDUELSPECIFICPLAYERDATA_H
#define QUESTOBJECTIVEDUELSPECIFICPLAYERDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveData.h"

class QuestObjectiveDuelSpecificPlayerData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEDUELSPECIFICPLAYERDATA_H