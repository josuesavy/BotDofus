#ifndef GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayArenaFighterStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaFighterStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaFighterStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaFighterStatusMessage(FuncTree tree);
  GameRolePlayArenaFighterStatusMessage();

  uint fightId;
  double playerId;
  bool accepted;

private:
  void _fightIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _acceptedFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H