#ifndef GAMEROLEPLAYFREESOULREQUESTMESSAGE_H
#define GAMEROLEPLAYFREESOULREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayFreeSoulRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayFreeSoulRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayFreeSoulRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayFreeSoulRequestMessage(FuncTree tree);
  GameRolePlayFreeSoulRequestMessage();
};

#endif // GAMEROLEPLAYFREESOULREQUESTMESSAGE_H