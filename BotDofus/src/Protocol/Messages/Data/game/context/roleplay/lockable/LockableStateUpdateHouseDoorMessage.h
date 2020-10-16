#ifndef LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H
#define LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/lockable/LockableStateUpdateAbstractMessage.h"

class LockableStateUpdateHouseDoorMessage : public LockableStateUpdateAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableStateUpdateHouseDoorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableStateUpdateHouseDoorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableStateUpdateHouseDoorMessage(FuncTree tree);
  LockableStateUpdateHouseDoorMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
};

#endif // LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H