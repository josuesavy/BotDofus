#ifndef GAMEACTIONFIGHTCHANGELOOKMESSAGE_H
#define GAMEACTIONFIGHTCHANGELOOKMESSAGE_H

#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightChangeLookMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightChangeLookMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightChangeLookMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightChangeLookMessage(FuncTree tree);
  GameActionFightChangeLookMessage();

  double targetId;
  QSharedPointer<EntityLook> entityLook;

private:
  void _targetIdFunc(Reader *input);
  void _entityLooktreeFunc(Reader *input);

  FuncTree _entityLooktree;
};

#endif // GAMEACTIONFIGHTCHANGELOOKMESSAGE_H