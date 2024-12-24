#ifndef GAMEACTIONFIGHTCHANGELOOKMESSAGE_H
#define GAMEACTIONFIGHTCHANGELOOKMESSAGE_H

#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

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