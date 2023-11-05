#ifndef SOUNDBONESDATA_H
#define SOUNDBONESDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SoundBonesData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QList<QString> getKeys() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QList<QString> m_keys;
};

#endif // SOUNDBONESDATA_H