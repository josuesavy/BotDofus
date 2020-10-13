#ifndef AUTHENTICATIONTICKETACCEPTEDMESSAGE_H
#define AUTHENTICATIONTICKETACCEPTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AuthenticationTicketAcceptedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AuthenticationTicketAcceptedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AuthenticationTicketAcceptedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AuthenticationTicketAcceptedMessage(FuncTree tree);
  AuthenticationTicketAcceptedMessage();
};

#endif // AUTHENTICATIONTICKETACCEPTEDMESSAGE_H