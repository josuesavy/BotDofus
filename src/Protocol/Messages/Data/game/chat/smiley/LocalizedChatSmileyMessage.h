#ifndef LOCALIZEDCHATSMILEYMESSAGE_H
#define LOCALIZEDCHATSMILEYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/smiley/ChatSmileyMessage.h"

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