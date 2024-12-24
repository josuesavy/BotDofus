#ifndef PARTYNEWGUESTMESSAGE_H
#define PARTYNEWGUESTMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

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