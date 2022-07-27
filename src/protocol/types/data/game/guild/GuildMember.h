#ifndef GUILDMEMBER_H
#define GUILDMEMBER_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/character/guild/note/PlayerNote.h"
#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildMember : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMember(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMember(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMember(FuncTree tree);
  GuildMember();
  bool operator==(const GuildMember &compared);

  int breed;
  bool sex;
  uint rankId;
  double enrollmentDate;
  double givenExperience;
  uint experienceGivenPercent;
  uint connected;
  int alignmentSide;
  uint hoursSinceLastConnection;
  uint moodSmileyId;
  uint accountId;
  int achievementPoints;
  QSharedPointer<PlayerStatus> status;
  bool havenBagShared;
  PlayerNote note;

private:
  void deserializeByteBoxes(Reader *input);
  void _breedFunc(Reader *input);
  void _rankIdFunc(Reader *input);
  void _enrollmentDateFunc(Reader *input);
  void _givenExperienceFunc(Reader *input);
  void _experienceGivenPercentFunc(Reader *input);
  void _connectedFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);
  void _hoursSinceLastConnectionFunc(Reader *input);
  void _moodSmileyIdFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _achievementPointsFunc(Reader *input);
  void _statustreeFunc(Reader *input);
  void _notetreeFunc(Reader *input);

  FuncTree _statustree;
  FuncTree _notetree;
};

#endif // GUILDMEMBER_H