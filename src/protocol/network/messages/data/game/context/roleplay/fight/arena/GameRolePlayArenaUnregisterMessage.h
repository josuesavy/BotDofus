#ifndef GAMEROLEPLAYARENAUNREGISTERMESSAGE_H
#define GAMEROLEPLAYARENAUNREGISTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayArenaUnregisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaUnregisterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaUnregisterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaUnregisterMessage(FuncTree tree);
  GameRolePlayArenaUnregisterMessage();
};

#endif // GAMEROLEPLAYARENAUNREGISTERMESSAGE_H