#ifndef BREACHINVITATIONOFFERMESSAGE_H
#define BREACHINVITATIONOFFERMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachInvitationOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachInvitationOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachInvitationOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachInvitationOfferMessage(FuncTree tree);
  BreachInvitationOfferMessage();

  CharacterMinimalInformations host;
  uint timeLeftBeforeCancel;

private:
  void _hosttreeFunc(Reader *input);
  void _timeLeftBeforeCancelFunc(Reader *input);

  FuncTree _hosttree;
};

#endif // BREACHINVITATIONOFFERMESSAGE_H