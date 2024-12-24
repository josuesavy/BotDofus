#ifndef FRIENDONLINEINFORMATIONS_H
#define FRIENDONLINEINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/network/types/data/game/friend/FriendInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/enums/data/PlayableBreedEnum.h"
#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"

class FriendOnlineInformations : public FriendInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendOnlineInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendOnlineInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendOnlineInformations(FuncTree tree);
  FriendOnlineInformations();
  bool operator==(const FriendOnlineInformations &compared);

  double playerId;
  QString playerName;
  uint level;
  int alignmentSide;
  int breed;
  bool sex;
  QSharedPointer<GuildInformations> guildInfo;
  uint moodSmileyId;
  QSharedPointer<PlayerStatus> status;
  bool havenBagShared;

private:
  void deserializeByteBoxes(Reader *input);
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);
  void _moodSmileyIdFunc(Reader *input);
  void _statustreeFunc(Reader *input);

  FuncTree _guildInfotree;
  FuncTree _statustree;
};

#endif // FRIENDONLINEINFORMATIONS_H