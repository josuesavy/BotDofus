#ifndef BREACHINVITATIONCLOSEMESSAGE_H
#define BREACHINVITATIONCLOSEMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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