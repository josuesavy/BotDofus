#ifndef CHANGEHAVENBAGROOMREQUESTMESSAGE_H
#define CHANGEHAVENBAGROOMREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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