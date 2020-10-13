#ifndef GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H
#define GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/fight/AbstractGameActionFightTargetedAbilityMessage.h"

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