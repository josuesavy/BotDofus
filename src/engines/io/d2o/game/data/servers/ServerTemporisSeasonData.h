#ifndef SERVERTEMPORISSEASONDATA_H
#define SERVERTEMPORISSEASONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ServerTemporisSeasonData : public AbstractGameData
{
public:
  int getUid() const;
  uint getSeasonNumber() const;
  QString getInformation() const;
  double getBeginning() const;
  double getClosure() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_uid;
  uint m_seasonNumber;
  QString m_information;
  double m_beginning;
  double m_closure;
};

#endif // SERVERTEMPORISSEASONDATA_H