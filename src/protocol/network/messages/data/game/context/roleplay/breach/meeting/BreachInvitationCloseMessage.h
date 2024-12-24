#ifndef BREACHINVITATIONCLOSEMESSAGE_H
#define BREACHINVITATIONCLOSEMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachInvitationCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachInvitationCloseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachInvitationCloseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachInvitationCloseMessage(FuncTree tree);
  BreachInvitationCloseMessage();

  CharacterMinimalInformations host;

private:
  void _hosttreeFunc(Reader *input);

  FuncTree _hosttree;
};

#endif // BREACHINVITATIONCLOSEMESSAGE_H