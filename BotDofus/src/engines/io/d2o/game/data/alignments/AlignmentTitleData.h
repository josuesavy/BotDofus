#ifndef ALIGNMENTTITLEDATA_H
#define ALIGNMENTTITLEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class AlignmentTitleData : public AbstractGameData
{
public:
  int getSideId() const;
  QList<int> getNamesId() const;
  QList<int> getShortsId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_sideId;
  QList<int> m_namesId;
  QList<int> m_shortsId;
};

#endif // ALIGNMENTTITLEDATA_H