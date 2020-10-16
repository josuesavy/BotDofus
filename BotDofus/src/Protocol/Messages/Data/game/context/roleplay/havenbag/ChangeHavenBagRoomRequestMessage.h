#ifndef CHANGEHAVENBAGROOMREQUESTMESSAGE_H
#define CHANGEHAVENBAGROOMREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChangeHavenBagRoomRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChangeHavenBagRoomRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChangeHavenBagRoomRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChangeHavenBagRoomRequestMessage(FuncTree tree);
  ChangeHavenBagRoomRequestMessage();

  uint roomId;

private:
  void _roomIdFunc(Reader *input);
};

#endif // CHANGEHAVENBAGROOMREQUESTMESSAGE_H