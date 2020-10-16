#ifndef EMOTEPLAYREQUESTMESSAGE_H
#define EMOTEPLAYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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