#ifndef PARTYCANNOTJOINERRORMESSAGE_H
#define PARTYCANNOTJOINERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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