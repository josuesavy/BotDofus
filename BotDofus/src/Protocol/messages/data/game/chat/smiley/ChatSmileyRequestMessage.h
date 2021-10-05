#ifndef CHATSMILEYREQUESTMESSAGE_H
#define CHATSMILEYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChatSmileyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatSmileyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatSmileyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatSmileyRequestMessage(FuncTree tree);
  ChatSmileyRequestMessage();

  uint smileyId;

private:
  void _smileyIdFunc(Reader *input);
};

#endif // CHATSMILEYREQUESTMESSAGE_H