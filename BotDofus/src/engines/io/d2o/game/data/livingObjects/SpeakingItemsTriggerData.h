#ifndef SPEAKINGITEMSTRIGGERDATA_H
#define SPEAKINGITEMSTRIGGERDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class SpeakingItemsTriggerData : public AbstractGameData
{
public:
  int getTriggersId() const;
  QList<int> getTextIds() const;
  QList<int> getStates() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_triggersId;
  QList<int> m_textIds;
  QList<int> m_states;
};

#endif // SPEAKINGITEMSTRIGGERDATA_H