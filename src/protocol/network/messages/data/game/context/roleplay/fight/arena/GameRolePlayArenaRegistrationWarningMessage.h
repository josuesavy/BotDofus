#ifndef GAMEROLEPLAYARENAREGISTRATIONWARNINGMESSAGE_H
#define GAMEROLEPLAYARENAREGISTRATIONWARNINGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaRegistrationWarningMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaRegistrationWarningMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaRegistrationWarningMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaRegistrationWarningMessage(FuncTree tree);
  GameRolePlayArenaRegistrationWarningMessage();

  uint battleMode;

private:
  void _battleModeFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAREGISTRATIONWARNINGMESSAGE_H