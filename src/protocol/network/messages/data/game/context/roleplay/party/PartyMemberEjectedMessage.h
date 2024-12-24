#ifndef PARTYMEMBEREJECTEDMESSAGE_H
#define PARTYMEMBEREJECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/PartyMemberRemoveMessage.h"

class PartyMemberEjectedMessage : public PartyMemberRemoveMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberEjectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberEjectedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberEjectedMessage(FuncTree tree);
  PartyMemberEjectedMessage();

  double kickerId;

private:
  void _kickerIdFunc(Reader *input);
};

#endif // PARTYMEMBEREJECTEDMESSAGE_H