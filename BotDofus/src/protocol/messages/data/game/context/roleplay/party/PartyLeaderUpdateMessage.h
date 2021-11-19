#ifndef PARTYLEADERUPDATEMESSAGE_H
#define PARTYLEADERUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

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