#ifndef SPEAKINGITEMTEXTDATA_H
#define SPEAKINGITEMTEXTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SpeakingItemTextData : public AbstractGameData
{
public:
  int getTextId() const;
  double getTextProba() const;
  uint getTextStringId() const;
  int getTextLevel() const;
  int getTextSound() const;
  QString getTextRestriction() const;
  QString getTextString() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_textId;
  double m_textProba;
  uint m_textStringId;
  int m_textLevel;
  int m_textSound;
  QString m_textRestriction;
};

#endif // SPEAKINGITEMTEXTDATA_H