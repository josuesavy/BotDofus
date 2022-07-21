#ifndef GUILDRANKNAMESUGGESTIONDATA_H
#define GUILDRANKNAMESUGGESTIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class GuildRankNameSuggestionData : public AbstractGameData
{
public:
  QString getUiKey() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_uiKey;
};

#endif // GUILDRANKNAMESUGGESTIONDATA_H