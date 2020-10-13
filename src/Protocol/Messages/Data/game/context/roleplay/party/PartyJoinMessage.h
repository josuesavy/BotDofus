#ifndef PARTYJOINMESSAGE_H
#define PARTYJOINMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyJoinMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyJoinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyJoinMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyJoinMessage(FuncTree tree);
  PartyJoinMessage();

  uint partyType;
  double partyLeaderId;
  uint maxParticipants;
  QList<QSharedPointer<PartyMemberInformations>> members;
  QList<QSharedPointer<PartyGuestInformations>> guests;
  bool restricted;
  QString partyName;

private:
  void _partyTypeFunc(Reader *input);
  void _partyLeaderIdFunc(Reader *input);
  void _maxParticipantsFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);
  void _gueststreeFunc(Reader *input);
  void _guestsFunc(Reader *input);
  void _restrictedFunc(Reader *input);
  void _partyNameFunc(Reader *input);

  FuncTree _memberstree;
  FuncTree _gueststree;
};

#endif // PARTYJOINMESSAGE_H