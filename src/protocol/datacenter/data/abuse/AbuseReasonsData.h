#ifndef ABUSEREASONSDATA_H
#define ABUSEREASONSDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AbuseReasonsData : public AbstractGameData
{
public:
  uint getAbuseReasonId() const;
  uint getMask() const;
  int getReasonTextId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_abuseReasonId;
  uint m_mask;
  int m_reasonTextId;
};

#endif // ABUSEREASONSDATA_H