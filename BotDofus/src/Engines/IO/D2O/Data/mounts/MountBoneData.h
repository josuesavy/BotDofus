#ifndef MOUNTBONEDATA_H
#define MOUNTBONEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MountBoneData : public AbstractGameData
{
public:
  uint getId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
};

#endif // MOUNTBONEDATA_H