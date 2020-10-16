#ifndef PARTYNEWGUESTMESSAGE_H
#define PARTYNEWGUESTMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyNewGuestMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyNewGuestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyNewGuestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyNewGuestMessage(FuncTree tree);
  PartyNewGuestMessage();

  QSharedPointer<PartyGuestInformations> guest;

private:
  void _guesttreeFunc(Reader *input);

  FuncTree _guesttree;
};

#endif // PARTYNEWGUESTMESSAGE_H