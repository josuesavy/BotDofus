#ifndef LIVINGOBJECTSKINJNTMOODDATA_H
#define LIVINGOBJECTSKINJNTMOODDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class LivingObjectSkinJntMoodData : public AbstractGameData
{
public:
  int getSkinId() const;
  QList<QList<int>> getMoods() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_skinId;
  QList<QList<int>> m_moods;
};

#endif // LIVINGOBJECTSKINJNTMOODDATA_H