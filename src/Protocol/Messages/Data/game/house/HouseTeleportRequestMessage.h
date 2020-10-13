#ifndef HOUSETELEPORTREQUESTMESSAGE_H
#define HOUSETELEPORTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseTeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseTeleportRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseTeleportRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseTeleportRequestMessage(FuncTree tree);
  HouseTeleportRequestMessage();

  uint houseId;
  uint houseInstanceId;

private:
  void _houseIdFunc(Reader *input);
  void _houseInstanceIdFunc(Reader *input);
};

#endif // HOUSETELEPORTREQUESTMESSAGE_H