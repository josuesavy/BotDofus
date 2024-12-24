#ifndef GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H
#define GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTeleportOnSameMapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightTeleportOnSameMapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightTeleportOnSameMapMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightTeleportOnSameMapMessage(FuncTree tree);
  GameActionFightTeleportOnSameMapMessage();

  double targetId;
  int cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H