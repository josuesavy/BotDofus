#ifndef ENTERHAVENBAGREQUESTMESSAGE_H
#define ENTERHAVENBAGREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class EnterHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EnterHavenBagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EnterHavenBagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EnterHavenBagRequestMessage(FuncTree tree);
  EnterHavenBagRequestMessage();

  double havenBagOwner;

private:
  void _havenBagOwnerFunc(Reader *input);
};

#endif // ENTERHAVENBAGREQUESTMESSAGE_H