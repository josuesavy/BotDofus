#ifndef AUTHENTICATIONTICKETREFUSEDMESSAGE_H
#define AUTHENTICATIONTICKETREFUSEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AuthenticationTicketRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AuthenticationTicketRefusedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AuthenticationTicketRefusedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AuthenticationTicketRefusedMessage(FuncTree tree);
  AuthenticationTicketRefusedMessage();
};

#endif // AUTHENTICATIONTICKETREFUSEDMESSAGE_H