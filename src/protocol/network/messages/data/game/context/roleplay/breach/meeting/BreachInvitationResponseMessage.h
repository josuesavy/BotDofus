#ifndef BREACHINVITATIONRESPONSEMESSAGE_H
#define BREACHINVITATIONRESPONSEMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachInvitationResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachInvitationResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachInvitationResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachInvitationResponseMessage(FuncTree tree);
  BreachInvitationResponseMessage();

  CharacterMinimalInformations guest;
  bool accept;

private:
  void _guesttreeFunc(Reader *input);
  void _acceptFunc(Reader *input);

  FuncTree _guesttree;
};

#endif // BREACHINVITATIONRESPONSEMESSAGE_H