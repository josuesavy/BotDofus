#ifndef COMPASSUPDATEPARTYMEMBERMESSAGE_H
#define COMPASSUPDATEPARTYMEMBERMESSAGE_H

#include "src/protocol/types/data/game/context/MapCoordinates.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/atlas/compass/CompassUpdateMessage.h"

class CompassUpdatePartyMemberMessage : public CompassUpdateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CompassUpdatePartyMemberMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CompassUpdatePartyMemberMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CompassUpdatePartyMemberMessage(FuncTree tree);
  CompassUpdatePartyMemberMessage();

  double memberId;
  bool active;

private:
  void _memberIdFunc(Reader *input);
  void _activeFunc(Reader *input);
};

#endif // COMPASSUPDATEPARTYMEMBERMESSAGE_H