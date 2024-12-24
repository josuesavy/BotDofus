#ifndef QUESTOBJECTIVEBRINGITEMTONPCDATA_H
#define QUESTOBJECTIVEBRINGITEMTONPCDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveBringItemToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEBRINGITEMTONPCDATA_H