#ifndef LOCKABLESTATEUPDATESTORAGEMESSAGE_H
#define LOCKABLESTATEUPDATESTORAGEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/lockable/LockableStateUpdateAbstractMessage.h"

class LockableStateUpdateStorageMessage : public LockableStateUpdateAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableStateUpdateStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableStateUpdateStorageMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableStateUpdateStorageMessage(FuncTree tree);
  LockableStateUpdateStorageMessage();

  double mapId;
  uint elementId;

private:
  void _mapIdFunc(Reader *input);
  void _elementIdFunc(Reader *input);
};

#endif // LOCKABLESTATEUPDATESTORAGEMESSAGE_H