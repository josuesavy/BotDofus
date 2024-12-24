#ifndef GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H
#define GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/fight/AbstractGameActionFightTargetedAbilityMessage.h"

class GameActionFightCloseCombatMessage : public AbstractGameActionFightTargetedAbilityMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightCloseCombatMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightCloseCombatMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightCloseCombatMessage(FuncTree tree);
  GameActionFightCloseCombatMessage();

  uint weaponGenericId;

private:
  void _weaponGenericIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H