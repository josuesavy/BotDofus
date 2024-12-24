#ifndef INVITEINHAVENBAGMESSAGE_H
#define INVITEINHAVENBAGMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class InviteInHavenBagMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InviteInHavenBagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InviteInHavenBagMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InviteInHavenBagMessage(FuncTree tree);
  InviteInHavenBagMessage();

  CharacterMinimalInformations guestInformations;
  bool accept;

private:
  void _guestInformationstreeFunc(Reader *input);
  void _acceptFunc(Reader *input);

  FuncTree _guestInformationstree;
};

#endif // INVITEINHAVENBAGMESSAGE_H