#ifndef SOUNDUIDATA_H
#define SOUNDUIDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundUiElementData.h"

class SoundUiData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getUiName() const;
  QString getOpenFile() const;
  QString getCloseFile() const;
  QList<SoundUiElementData> getSubElements() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_uiName;
  QString m_openFile;
  QString m_closeFile;
  QList<SoundUiElementData> m_subElements;
};

#endif // SOUNDUIDATA_H