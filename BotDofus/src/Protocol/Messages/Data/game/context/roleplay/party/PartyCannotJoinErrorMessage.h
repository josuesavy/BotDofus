#ifndef PARTYCANNOTJOINERRORMESSAGE_H
#define PARTYCANNOTJOINERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyCannotJoinErrorMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyCannotJoinErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyCannotJoinErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyCannotJoinErrorMessage(FuncTree tree);
  PartyCannotJoinErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // PARTYCANNOTJOINERRORMESSAGE_H