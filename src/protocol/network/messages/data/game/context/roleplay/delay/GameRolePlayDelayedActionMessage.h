#ifndef GAMEROLEPLAYDELAYEDACTIONMESSAGE_H
#define GAMEROLEPLAYDELAYEDACTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayDelayedActionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayDelayedActionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayDelayedActionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayDelayedActionMessage(FuncTree tree);
  GameRolePlayDelayedActionMessage();

  double delayedCharacterId;
  uint delayTypeId;
  double delayEndTime;

private:
  void _delayedCharacterIdFunc(Reader *input);
  void _delayTypeIdFunc(Reader *input);
  void _delayEndTimeFunc(Reader *input);
};

#endif // GAMEROLEPLAYDELAYEDACTIONMESSAGE_H