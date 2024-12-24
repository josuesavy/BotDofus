#ifndef QUESTOBJECTIVECRAFTITEMDATA_H
#define QUESTOBJECTIVECRAFTITEMDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveCraftItemData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVECRAFTITEMDATA_H