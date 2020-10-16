#ifndef COMPASSUPDATEPARTYMEMBERMESSAGE_H
#define COMPASSUPDATEPARTYMEMBERMESSAGE_H

#include "src/Protocol/Types/Data/game/context/MapCoordinates.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/atlas/compass/CompassUpdateMessage.h"

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