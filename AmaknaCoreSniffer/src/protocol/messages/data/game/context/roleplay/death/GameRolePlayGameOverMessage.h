#ifndef GAMEROLEPLAYGAMEOVERMESSAGE_H
#define GAMEROLEPLAYGAMEOVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayGameOverMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayGameOverMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayGameOverMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayGameOverMessage(FuncTree tree);
  GameRolePlayGameOverMessage();
};

#endif // GAMEROLEPLAYGAMEOVERMESSAGE_H