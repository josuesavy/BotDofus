#ifndef GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H
#define GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayDelayedActionFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayDelayedActionFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayDelayedActionFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayDelayedActionFinishedMessage(FuncTree tree);
  GameRolePlayDelayedActionFinishedMessage();

  double delayedCharacterId;
  uint delayTypeId;

private:
  void _delayedCharacterIdFunc(Reader *input);
  void _delayTypeIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H