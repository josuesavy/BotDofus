#ifndef ALLIANCEMEMBERSHIPMESSAGE_H
#define ALLIANCEMEMBERSHIPMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/alliance/AllianceJoinedMessage.h"

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