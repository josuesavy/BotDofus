#ifndef BREACHINVITATIONANSWERMESSAGE_H
#define BREACHINVITATIONANSWERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachInvitationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachInvitationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachInvitationAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachInvitationAnswerMessage(FuncTree tree);
  BreachInvitationAnswerMessage();

  bool accept;

private:
  void _acceptFunc(Reader *input);
};

#endif // BREACHINVITATIONANSWERMESSAGE_H