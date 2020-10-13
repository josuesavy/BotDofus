#ifndef PARTYUPDATEMESSAGE_H
#define PARTYUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

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