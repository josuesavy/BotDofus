#ifndef GUILDMEMBERINFO_H
#define GUILDMEMBERINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/guild/note/PlayerNote.h"
#include "src/protocol/types/data/game/social/SocialMember.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildMemberInfo : public SocialMember
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberInfo(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberInfo(FuncTree tree);
  GuildMemberInfo();
  bool operator==(const GuildMemberInfo &compared);

  double givenExperience;
  uint experienceGivenPercent;
  int alignmentSide;
  uint moodSmileyId;
  int achievementPoints;
  bool havenBagShared;
  PlayerNote note;

private:
  void _givenExperienceFunc(Reader *input);
  void _experienceGivenPercentFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);
  void _moodSmileyIdFunc(Reader *input);
  void _achievementPointsFunc(Reader *input);
  void _havenBagSharedFunc(Reader *input);
  void _notetreeFunc(Reader *input);

  FuncTree _notetree;
};

#endif // GUILDMEMBERINFO_H