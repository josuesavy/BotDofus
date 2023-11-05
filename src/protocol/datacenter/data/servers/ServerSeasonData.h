#ifndef SERVERSEASONDATA_H
#define SERVERSEASONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ServerSeasonData : public AbstractGameData
{
public:
  int getUid() const;
  uint getSeasonNumber() const;
  QString getInformation() const;
  double getBeginning() const;
  double getClosure() const;
  double getResetDate() const;
  uint getFlagObjectId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_uid;
  uint m_seasonNumber;
  QString m_information;
  double m_beginning;
  double m_closure;
  double m_resetDate;
  uint m_flagObjectId;
};

#endif // SERVERSEASONDATA_H