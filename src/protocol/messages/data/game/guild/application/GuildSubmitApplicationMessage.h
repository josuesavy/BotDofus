#ifndef GUILDSUBMITAPPLICATIONMESSAGE_H
#define GUILDSUBMITAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildSubmitApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildSubmitApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildSubmitApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildSubmitApplicationMessage(FuncTree tree);
  GuildSubmitApplicationMessage();

  QString applyText;
  uint guildId;
  uint timeSpent;
  QString filterLanguage;
  QString filterAmbiance;
  QString filterPlaytime;
  QString filterInterest;
  QString filterMinMaxGuildLevel;
  QString filterRecruitmentType;
  QString filterMinMaxCharacterLevel;
  QString filterMinMaxAchievement;
  QString filterSearchName;
  QString filterLastSort;

private:
  void _applyTextFunc(Reader *input);
  void _guildIdFunc(Reader *input);
  void _timeSpentFunc(Reader *input);
  void _filterLanguageFunc(Reader *input);
  void _filterAmbianceFunc(Reader *input);
  void _filterPlaytimeFunc(Reader *input);
  void _filterInterestFunc(Reader *input);
  void _filterMinMaxGuildLevelFunc(Reader *input);
  void _filterRecruitmentTypeFunc(Reader *input);
  void _filterMinMaxCharacterLevelFunc(Reader *input);
  void _filterMinMaxAchievementFunc(Reader *input);
  void _filterSearchNameFunc(Reader *input);
  void _filterLastSortFunc(Reader *input);
};

#endif // GUILDSUBMITAPPLICATIONMESSAGE_H