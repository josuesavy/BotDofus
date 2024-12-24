#ifndef SURRENDERINFOREQUESTMESSAGE_H
#define SURRENDERINFOREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderInfoRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderInfoRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderInfoRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderInfoRequestMessage(FuncTree tree);
  SurrenderInfoRequestMessage();
};

#endif // SURRENDERINFOREQUESTMESSAGE_H