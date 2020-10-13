#ifndef LIVINGOBJECTMESSAGEMESSAGE_H
#define LIVINGOBJECTMESSAGEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class LivingObjectMessageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LivingObjectMessageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LivingObjectMessageMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LivingObjectMessageMessage(FuncTree tree);
  LivingObjectMessageMessage();

  uint msgId;
  uint timeStamp;
  QString owner;
  uint objectGenericId;

private:
  void _msgIdFunc(Reader *input);
  void _timeStampFunc(Reader *input);
  void _ownerFunc(Reader *input);
  void _objectGenericIdFunc(Reader *input);
};

#endif // LIVINGOBJECTMESSAGEMESSAGE_H