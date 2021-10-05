#ifndef QUESTOBJECTIVECRAFTITEMDATA_H
#define QUESTOBJECTIVECRAFTITEMDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveData.h"

class QuestObjectiveCraftItemData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVECRAFTITEMDATA_H