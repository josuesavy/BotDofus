#ifndef GAMEROLEPLAYARENAREGISTERMESSAGE_H
#define GAMEROLEPLAYARENAREGISTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  uint arenaType;

private:
  void _arenaTypeFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAREGISTERMESSAGE_H