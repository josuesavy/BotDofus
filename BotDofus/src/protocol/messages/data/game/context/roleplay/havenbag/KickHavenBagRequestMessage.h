#ifndef KICKHAVENBAGREQUESTMESSAGE_H
#define KICKHAVENBAGREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class KickHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KickHavenBagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KickHavenBagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KickHavenBagRequestMessage(FuncTree tree);
  KickHavenBagRequestMessage();

  double guestId;

private:
  void _guestIdFunc(Reader *input);
};

#endif // KICKHAVENBAGREQUESTMESSAGE_H