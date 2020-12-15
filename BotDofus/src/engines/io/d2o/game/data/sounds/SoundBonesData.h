#ifndef SOUNDBONESDATA_H
#define SOUNDBONESDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundAnimationData.h"

class SoundBonesData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QList<QString> getKeys() const;
  QList<QList<SoundAnimationData>> getValues() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QList<QString> m_keys;
  QList<QList<SoundAnimationData>> m_values;
};

#endif // SOUNDBONESDATA_H