#ifndef EXITHAVENBAGREQUESTMESSAGE_H
#define EXITHAVENBAGREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExitHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExitHavenBagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExitHavenBagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExitHavenBagRequestMessage(FuncTree tree);
  ExitHavenBagRequestMessage();
};

#endif // EXITHAVENBAGREQUESTMESSAGE_H