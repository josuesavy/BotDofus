#ifndef QUESTOBJECTIVEGOTONPCDATA_H
#define QUESTOBJECTIVEGOTONPCDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveGoToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEGOTONPCDATA_H