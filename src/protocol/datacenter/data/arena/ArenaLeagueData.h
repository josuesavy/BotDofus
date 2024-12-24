#ifndef ARENALEAGUEDATA_H
#define ARENALEAGUEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ArenaLeagueData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getOrnamentId() const;
  QString getIcon() const;
  QString getIllus() const;
  bool getIsLastLeague() const;
  int getLowRatingBound() const;
  int getHighRatingBound() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_ornamentId;
  QString m_icon;
  QString m_illus;
  bool m_isLastLeague;
  int m_lowRatingBound;
  int m_highRatingBound;
};

#endif // ARENALEAGUEDATA_H