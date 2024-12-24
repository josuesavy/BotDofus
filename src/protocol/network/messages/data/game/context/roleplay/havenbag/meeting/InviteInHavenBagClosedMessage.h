#ifndef INVITEINHAVENBAGCLOSEDMESSAGE_H
#define INVITEINHAVENBAGCLOSEDMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class InviteInHavenBagClosedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InviteInHavenBagClosedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InviteInHavenBagClosedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InviteInHavenBagClosedMessage(FuncTree tree);
  InviteInHavenBagClosedMessage();

  CharacterMinimalInformations hostInformations;

private:
  void _hostInformationstreeFunc(Reader *input);

  FuncTree _hostInformationstree;
};

#endif // INVITEINHAVENBAGCLOSEDMESSAGE_H