#ifndef STEALTHBONESDATA_H
#define STEALTHBONESDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class StealthBonesData : public AbstractGameData
{
public:
  uint getId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
};

#endif // STEALTHBONESDATA_H