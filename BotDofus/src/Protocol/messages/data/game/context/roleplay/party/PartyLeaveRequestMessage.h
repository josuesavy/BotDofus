#ifndef PARTYLEAVEREQUESTMESSAGE_H
#define PARTYLEAVEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLeaveRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLeaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLeaveRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLeaveRequestMessage(FuncTree tree);
  PartyLeaveRequestMessage();
};

#endif // PARTYLEAVEREQUESTMESSAGE_H