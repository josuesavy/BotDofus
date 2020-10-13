#ifndef PARTYNAMESETREQUESTMESSAGE_H
#define PARTYNAMESETREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameSetRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyNameSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyNameSetRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyNameSetRequestMessage(FuncTree tree);
  PartyNameSetRequestMessage();

  QString partyName;

private:
  void _partyNameFunc(Reader *input);
};

#endif // PARTYNAMESETREQUESTMESSAGE_H