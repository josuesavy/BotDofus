#ifndef QUESTOBJECTIVEDATA_H
#define QUESTOBJECTIVEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class QuestObjectiveData : public AbstractGameData
{
public:
  uint getId() const;
  uint getStepId() const;
  uint getTypeId() const;
  int getDialogId() const;
  double getMapId() const;
  QString getDialog() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_stepId;
  uint m_typeId;
  int m_dialogId;
  double m_mapId;
};

#endif // QUESTOBJECTIVEDATA_H