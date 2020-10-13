#ifndef QUESTOBJECTIVEBRINGITEMTONPCDATA_H
#define QUESTOBJECTIVEBRINGITEMTONPCDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveBringItemToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEBRINGITEMTONPCDATA_H