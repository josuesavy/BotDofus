#ifndef GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H
#define GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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