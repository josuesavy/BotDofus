#ifndef PLAYERSTATUSUPDATEMESSAGE_H
#define PLAYERSTATUSUPDATEMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PlayerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerStatusUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerStatusUpdateMessage(FuncTree tree);
  PlayerStatusUpdateMessage();

  uint accountId;
  double playerId;
  QSharedPointer<PlayerStatus> status;

private:
  void _accountIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _statustreeFunc(Reader *input);

  FuncTree _statustree;
};

#endif // PLAYERSTATUSUPDATEMESSAGE_H