#ifndef PARTYNAMESETREQUESTMESSAGE_H
#define PARTYNAMESETREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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