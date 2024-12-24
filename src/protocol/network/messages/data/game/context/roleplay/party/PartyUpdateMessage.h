#ifndef PARTYUPDATEMESSAGE_H
#define PARTYUPDATEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyUpdateMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyUpdateMessage(FuncTree tree);
  PartyUpdateMessage();

  QSharedPointer<PartyMemberInformations> memberInformations;

private:
  void _memberInformationstreeFunc(Reader *input);

  FuncTree _memberInformationstree;
};

#endif // PARTYUPDATEMESSAGE_H