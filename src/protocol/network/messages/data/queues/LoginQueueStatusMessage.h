#ifndef LOGINQUEUESTATUSMESSAGE_H
#define LOGINQUEUESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class LoginQueueStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LoginQueueStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LoginQueueStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LoginQueueStatusMessage(FuncTree tree);
  LoginQueueStatusMessage();

  uint position;
  uint total;

private:
  void _positionFunc(Reader *input);
  void _totalFunc(Reader *input);
};

#endif // LOGINQUEUESTATUSMESSAGE_H