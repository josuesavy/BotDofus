#ifndef TELEPORTREQUESTMESSAGE_H
#define TELEPORTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportRequestMessage(FuncTree tree);
  TeleportRequestMessage();

  uint sourceType;
  uint destinationType;
  double mapId;

private:
  void _sourceTypeFunc(Reader *input);
  void _destinationTypeFunc(Reader *input);
  void _mapIdFunc(Reader *input);
};

#endif // TELEPORTREQUESTMESSAGE_H