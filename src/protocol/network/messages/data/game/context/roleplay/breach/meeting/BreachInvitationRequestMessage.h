#ifndef BREACHINVITATIONREQUESTMESSAGE_H
#define BREACHINVITATIONREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachInvitationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachInvitationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachInvitationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachInvitationRequestMessage(FuncTree tree);
  BreachInvitationRequestMessage();

  QList<double> guests;

private:
  void _gueststreeFunc(Reader *input);
  void _guestsFunc(Reader *input);

  FuncTree _gueststree;
};

#endif // BREACHINVITATIONREQUESTMESSAGE_H