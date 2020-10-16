#ifndef GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H
#define GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayArenaRegistrationStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaRegistrationStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaRegistrationStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaRegistrationStatusMessage(FuncTree tree);
  GameRolePlayArenaRegistrationStatusMessage();

  bool registered;
  uint step;
  uint battleMode;

private:
  void _registeredFunc(Reader *input);
  void _stepFunc(Reader *input);
  void _battleModeFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H