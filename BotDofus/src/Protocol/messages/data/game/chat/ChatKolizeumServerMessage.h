#ifndef CHATKOLIZEUMSERVERMESSAGE_H
#define CHATKOLIZEUMSERVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/chat/ChatServerMessage.h"

class ChatKolizeumServerMessage : public ChatServerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatKolizeumServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatKolizeumServerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatKolizeumServerMessage(FuncTree tree);
  ChatKolizeumServerMessage();

  int originServerId;

private:
  void _originServerIdFunc(Reader *input);
};

#endif // CHATKOLIZEUMSERVERMESSAGE_H