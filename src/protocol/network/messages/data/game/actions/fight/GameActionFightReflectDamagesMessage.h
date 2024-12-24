#ifndef GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H
#define GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReflectDamagesMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightReflectDamagesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightReflectDamagesMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightReflectDamagesMessage(FuncTree tree);
  GameActionFightReflectDamagesMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H