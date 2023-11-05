#ifndef SOUNDUIDATA_H
#define SOUNDUIDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SoundUiData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getUiName() const;
  QString getOpenFile() const;
  QString getCloseFile() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_uiName;
  QString m_openFile;
  QString m_closeFile;
};

#endif // SOUNDUIDATA_H