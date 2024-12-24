#ifndef AUTHENTICATIONTICKETREFUSEDMESSAGE_H
#define AUTHENTICATIONTICKETREFUSEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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