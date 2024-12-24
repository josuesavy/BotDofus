#ifndef ALIGNMENTRANKJNTGIFTDATA_H
#define ALIGNMENTRANKJNTGIFTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class AlignmentRankJntGiftData : public AbstractGameData
{
public:
  int getId() const;
  QList<int> getGifts() const;
  QList<int> getLevels() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QList<int> m_gifts;
  QList<int> m_levels;
};

#endif // ALIGNMENTRANKJNTGIFTDATA_H