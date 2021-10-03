#ifndef CHATSMILEYMESSAGE_H
#define CHATSMILEYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChatSmileyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatSmileyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatSmileyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatSmileyMessage(FuncTree tree);
  ChatSmileyMessage();

  double entityId;
  uint smileyId;
  uint accountId;

private:
  void _entityIdFunc(Reader *input);
  void _smileyIdFunc(Reader *input);
  void _accountIdFunc(Reader *input);
};

#endif // CHATSMILEYMESSAGE_H