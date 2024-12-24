#ifndef LIVINGOBJECTDISSOCIATEMESSAGE_H
#define LIVINGOBJECTDISSOCIATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class LivingObjectDissociateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LivingObjectDissociateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LivingObjectDissociateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LivingObjectDissociateMessage(FuncTree tree);
  LivingObjectDissociateMessage();

  uint livingUID;
  uint livingPosition;

private:
  void _livingUIDFunc(Reader *input);
  void _livingPositionFunc(Reader *input);
};

#endif // LIVINGOBJECTDISSOCIATEMESSAGE_H