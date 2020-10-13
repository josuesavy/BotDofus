#ifndef GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H
#define GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/fight/GameActionFightDispellEffectMessage.h"

class GameActionFightTriggerEffectMessage : public GameActionFightDispellEffectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightTriggerEffectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightTriggerEffectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightTriggerEffectMessage(FuncTree tree);
  GameActionFightTriggerEffectMessage();
};

#endif // GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H