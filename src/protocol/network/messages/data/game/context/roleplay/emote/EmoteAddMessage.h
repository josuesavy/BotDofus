#ifndef EMOTEADDMESSAGE_H
#define EMOTEADDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class EmoteAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmoteAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmoteAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmoteAddMessage(FuncTree tree);
  EmoteAddMessage();

  uint emoteId;

private:
  void _emoteIdFunc(Reader *input);
};

#endif // EMOTEADDMESSAGE_H