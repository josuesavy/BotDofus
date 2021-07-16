#ifndef FRIENDINFORMATIONS_H
#define FRIENDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/friend/AbstractContactInformations.h"
#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FriendInformations : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendInformations(FuncTree tree);
  FriendInformations();
  bool operator==(const FriendInformations &compared);

  uint playerState;
  uint lastConnection;
  int achievementPoints;
  int leagueId;
  int ladderPosition;

private:
  void _playerStateFunc(Reader *input);
  void _lastConnectionFunc(Reader *input);
  void _achievementPointsFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
};

#endif // FRIENDINFORMATIONS_H