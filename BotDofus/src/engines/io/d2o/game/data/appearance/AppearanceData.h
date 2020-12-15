#ifndef APPEARANCEDATA_H
#define APPEARANCEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AppearanceData : public AbstractGameData
{
public:
  uint getId() const;
  uint getType() const;
  QString getData() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_type;
  QString m_data;
};

#endif // APPEARANCEDATA_H