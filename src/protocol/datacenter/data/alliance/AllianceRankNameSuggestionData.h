#ifndef ALLIANCERANKNAMESUGGESTIONDATA_H
#define ALLIANCERANKNAMESUGGESTIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AllianceRankNameSuggestionData : public AbstractGameData
{
public:
  QString getUiKey() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_uiKey;
};

#endif // ALLIANCERANKNAMESUGGESTIONDATA_H