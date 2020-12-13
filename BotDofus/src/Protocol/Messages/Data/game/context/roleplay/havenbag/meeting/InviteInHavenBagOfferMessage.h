#ifndef INVITEINHAVENBAGOFFERMESSAGE_H
#define INVITEINHAVENBAGOFFERMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class InviteInHavenBagOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InviteInHavenBagOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InviteInHavenBagOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InviteInHavenBagOfferMessage(FuncTree tree);
  InviteInHavenBagOfferMessage();

  CharacterMinimalInformations hostInformations;
  int timeLeftBeforeCancel;

private:
  void _hostInformationstreeFunc(Reader *input);
  void _timeLeftBeforeCancelFunc(Reader *input);

  FuncTree _hostInformationstree;
};

#endif // INVITEINHAVENBAGOFFERMESSAGE_H