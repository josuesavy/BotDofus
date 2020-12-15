#ifndef INCARNATIONDATA_H
#define INCARNATIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class IncarnationData : public AbstractGameData
{
public:
  uint getId() const;
  uint getMaleBoneId() const;
  uint getFemaleBoneId() const;
  QString getLookMale() const;
  QString getLookFemale() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_maleBoneId;
  uint m_femaleBoneId;
  QString m_lookMale;
  QString m_lookFemale;
};

#endif // INCARNATIONDATA_H