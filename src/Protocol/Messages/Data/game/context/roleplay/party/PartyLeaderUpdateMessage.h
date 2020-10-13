#ifndef PARTYLEADERUPDATEMESSAGE_H
#define PARTYLEADERUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyLeaderUpdateMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLeaderUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLeaderUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLeaderUpdateMessage(FuncTree tree);
  PartyLeaderUpdateMessage();

  double partyLeaderId;

private:
  void _partyLeaderIdFunc(Reader *input);
};

#endif // PARTYLEADERUPDATEMESSAGE_H