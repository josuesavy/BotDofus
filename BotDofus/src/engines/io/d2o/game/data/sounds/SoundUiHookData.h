#ifndef SOUNDUIHOOKDATA_H
#define SOUNDUIHOOKDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SoundUiHookData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_name;
};

#endif // SOUNDUIHOOKDATA_H