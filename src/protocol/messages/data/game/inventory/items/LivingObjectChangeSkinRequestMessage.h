#ifndef LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H
#define LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class LivingObjectChangeSkinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LivingObjectChangeSkinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LivingObjectChangeSkinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LivingObjectChangeSkinRequestMessage(FuncTree tree);
  LivingObjectChangeSkinRequestMessage();

  uint livingUID;
  uint livingPosition;
  uint skinId;

private:
  void _livingUIDFunc(Reader *input);
  void _livingPositionFunc(Reader *input);
  void _skinIdFunc(Reader *input);
};

#endif // LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H