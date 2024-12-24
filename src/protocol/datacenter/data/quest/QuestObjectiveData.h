#ifndef QUESTOBJECTIVEDATA_H
#define QUESTOBJECTIVEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class QuestObjectiveData : public AbstractGameData
{
public:
  uint getId() const;
  uint getStepId() const;
  uint getTypeId() const;
  int getDialogId() const;
  QPoint getCoords() const;
  double getMapId() const;
  QString getDialog() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_stepId;
  uint m_typeId;
  int m_dialogId;
  QPoint m_coords;
  double m_mapId;
};

#endif // QUESTOBJECTIVEDATA_H