#ifndef LIVINGOBJECTMESSAGEREQUESTMESSAGE_H
#define LIVINGOBJECTMESSAGEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class LivingObjectMessageRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LivingObjectMessageRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LivingObjectMessageRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LivingObjectMessageRequestMessage(FuncTree tree);
  LivingObjectMessageRequestMessage();

  uint msgId;
  QList<QString> parameters;
  uint livingObject;

private:
  void _msgIdFunc(Reader *input);
  void _parameterstreeFunc(Reader *input);
  void _parametersFunc(Reader *input);
  void _livingObjectFunc(Reader *input);

  FuncTree _parameterstree;
};

#endif // LIVINGOBJECTMESSAGEREQUESTMESSAGE_H