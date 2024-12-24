#ifndef LOCALIZEDCHATSMILEYMESSAGE_H
#define LOCALIZEDCHATSMILEYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/smiley/ChatSmileyMessage.h"

class LocalizedChatSmileyMessage : public ChatSmileyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LocalizedChatSmileyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LocalizedChatSmileyMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LocalizedChatSmileyMessage(FuncTree tree);
  LocalizedChatSmileyMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // LOCALIZEDCHATSMILEYMESSAGE_H