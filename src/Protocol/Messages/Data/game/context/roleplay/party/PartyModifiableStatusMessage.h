#ifndef PARTYMODIFIABLESTATUSMESSAGE_H
#define PARTYMODIFIABLESTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyModifiableStatusMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyModifiableStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyModifiableStatusMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyModifiableStatusMessage(FuncTree tree);
  PartyModifiableStatusMessage();

  bool enabled;

private:
  void _enabledFunc(Reader *input);
};

#endif // PARTYMODIFIABLESTATUSMESSAGE_H