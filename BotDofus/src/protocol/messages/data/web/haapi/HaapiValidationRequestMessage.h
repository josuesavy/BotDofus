#ifndef HAAPIVALIDATIONREQUESTMESSAGE_H
#define HAAPIVALIDATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HaapiValidationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiValidationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiValidationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiValidationRequestMessage(FuncTree tree);
  HaapiValidationRequestMessage();

  QString transaction;

private:
  void _transactionFunc(Reader *input);
};

#endif // HAAPIVALIDATIONREQUESTMESSAGE_H