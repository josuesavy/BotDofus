#ifndef ALLIANCEMEMBERSHIPMESSAGE_H
#define ALLIANCEMEMBERSHIPMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/AllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/alliance/AllianceJoinedMessage.h"

class AllianceMembershipMessage : public AllianceJoinedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMembershipMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMembershipMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMembershipMessage(FuncTree tree);
  AllianceMembershipMessage();
};

#endif // ALLIANCEMEMBERSHIPMESSAGE_H