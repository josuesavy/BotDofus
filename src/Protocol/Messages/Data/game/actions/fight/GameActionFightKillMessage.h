#ifndef GAMEACTIONFIGHTKILLMESSAGE_H
#define GAMEACTIONFIGHTKILLMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightKillMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightKillMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightKillMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightKillMessage(FuncTree tree);
  GameActionFightKillMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTKILLMESSAGE_H