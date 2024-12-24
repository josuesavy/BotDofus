#ifndef GAMEACTIONFIGHTDEATHMESSAGE_H
#define GAMEACTIONFIGHTDEATHMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDeathMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDeathMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDeathMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDeathMessage(FuncTree tree);
  GameActionFightDeathMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDEATHMESSAGE_H