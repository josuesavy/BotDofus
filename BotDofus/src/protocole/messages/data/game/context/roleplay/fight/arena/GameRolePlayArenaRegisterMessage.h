#ifndef GAMEROLEPLAYARENAREGISTERMESSAGE_H
#define GAMEROLEPLAYARENAREGISTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaRegisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaRegisterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaRegisterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaRegisterMessage(FuncTree tree);
  GameRolePlayArenaRegisterMessage();

  uint battleMode;

private:
  void _battleModeFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAREGISTERMESSAGE_H