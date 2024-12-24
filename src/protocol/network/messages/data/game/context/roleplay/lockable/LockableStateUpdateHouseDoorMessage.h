#ifndef LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H
#define LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/lockable/LockableStateUpdateAbstractMessage.h"

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