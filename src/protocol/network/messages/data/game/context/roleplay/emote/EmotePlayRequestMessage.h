#ifndef EMOTEPLAYREQUESTMESSAGE_H
#define EMOTEPLAYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class EmotePlayRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmotePlayRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmotePlayRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmotePlayRequestMessage(FuncTree tree);
  EmotePlayRequestMessage();

  uint emoteId;

private:
  void _emoteIdFunc(Reader *input);
};

#endif // EMOTEPLAYREQUESTMESSAGE_H