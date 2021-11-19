#ifndef GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H
#define GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/delay/GameRolePlayDelayedActionMessage.h"

class GameRolePlayDelayedObjectUseMessage : public GameRolePlayDelayedActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayDelayedObjectUseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayDelayedObjectUseMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayDelayedObjectUseMessage(FuncTree tree);
  GameRolePlayDelayedObjectUseMessage();

  uint objectGID;

private:
  void _objectGIDFunc(Reader *input);
};

#endif // GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H