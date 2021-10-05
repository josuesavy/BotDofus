#ifndef ABSTRACTPARTYMEMBERINFIGHTMESSAGE_H
#define ABSTRACTPARTYMEMBERINFIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class AbstractPartyMemberInFightMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractPartyMemberInFightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractPartyMemberInFightMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractPartyMemberInFightMessage(FuncTree tree);
  AbstractPartyMemberInFightMessage();

  uint reason;
  double memberId;
  uint memberAccountId;
  QString memberName;
  uint fightId;
  int timeBeforeFightStart;

private:
  void _reasonFunc(Reader *input);
  void _memberIdFunc(Reader *input);
  void _memberAccountIdFunc(Reader *input);
  void _memberNameFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _timeBeforeFightStartFunc(Reader *input);
};

#endif // ABSTRACTPARTYMEMBERINFIGHTMESSAGE_H