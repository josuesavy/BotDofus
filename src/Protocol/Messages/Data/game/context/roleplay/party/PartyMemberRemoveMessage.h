#ifndef PARTYMEMBERREMOVEMESSAGE_H
#define PARTYMEMBERREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyMemberRemoveMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberRemoveMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberRemoveMessage(FuncTree tree);
  PartyMemberRemoveMessage();

  double leavingPlayerId;

private:
  void _leavingPlayerIdFunc(Reader *input);
};

#endif // PARTYMEMBERREMOVEMESSAGE_H