#ifndef CHATSERVERMESSAGE_H
#define CHATSERVERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatAbstractServerMessage.h"

class ChatServerMessage : public ChatAbstractServerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatServerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatServerMessage(FuncTree tree);
  ChatServerMessage();

  double senderId;
  QString senderName;
  QString prefix;
  uint senderAccountId;

private:
  void _senderIdFunc(Reader *input);
  void _senderNameFunc(Reader *input);
  void _prefixFunc(Reader *input);
  void _senderAccountIdFunc(Reader *input);
};

#endif // CHATSERVERMESSAGE_H