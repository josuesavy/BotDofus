#ifndef PARTYNEWMEMBERMESSAGE_H
#define PARTYNEWMEMBERMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/PartyUpdateMessage.h"

class PartyNewMemberMessage : public PartyUpdateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyNewMemberMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyNewMemberMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyNewMemberMessage(FuncTree tree);
  PartyNewMemberMessage();
};

#endif // PARTYNEWMEMBERMESSAGE_H