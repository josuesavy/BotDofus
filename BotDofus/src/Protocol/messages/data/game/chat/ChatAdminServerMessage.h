#ifndef CHATADMINSERVERMESSAGE_H
#define CHATADMINSERVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/chat/ChatServerMessage.h"

class ChatAdminServerMessage : public ChatServerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatAdminServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatAdminServerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatAdminServerMessage(FuncTree tree);
  ChatAdminServerMessage();
};

#endif // CHATADMINSERVERMESSAGE_H