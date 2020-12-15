#ifndef PARTYLEAVEMESSAGE_H
#define PARTYLEAVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLeaveMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLeaveMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLeaveMessage(FuncTree tree);
  PartyLeaveMessage();
};

#endif // PARTYLEAVEMESSAGE_H