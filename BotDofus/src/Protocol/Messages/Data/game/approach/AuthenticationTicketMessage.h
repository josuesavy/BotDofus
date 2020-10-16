#ifndef AUTHENTICATIONTICKETMESSAGE_H
#define AUTHENTICATIONTICKETMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AuthenticationTicketMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AuthenticationTicketMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AuthenticationTicketMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AuthenticationTicketMessage(FuncTree tree);
  AuthenticationTicketMessage();

  QString lang;
  QString ticket;

private:
  void _langFunc(Reader *input);
  void _ticketFunc(Reader *input);
};

#endif // AUTHENTICATIONTICKETMESSAGE_H