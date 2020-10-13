#ifndef LOGINQUEUESTATUSMESSAGE_H
#define LOGINQUEUESTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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