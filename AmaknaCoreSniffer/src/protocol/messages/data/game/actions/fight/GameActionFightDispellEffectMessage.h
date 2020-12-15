#ifndef GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/fight/GameActionFightDispellMessage.h"

class GameActionFightDispellEffectMessage : public GameActionFightDispellMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDispellEffectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDispellEffectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDispellEffectMessage(FuncTree tree);
  GameActionFightDispellEffectMessage();

  uint boostUID;

private:
  void _boostUIDFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H