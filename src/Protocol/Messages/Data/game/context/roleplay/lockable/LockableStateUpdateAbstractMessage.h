#ifndef LOCKABLESTATEUPDATEABSTRACTMESSAGE_H
#define LOCKABLESTATEUPDATEABSTRACTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class LockableStateUpdateAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableStateUpdateAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableStateUpdateAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableStateUpdateAbstractMessage(FuncTree tree);
  LockableStateUpdateAbstractMessage();

  bool locked;

private:
  void _lockedFunc(Reader *input);
};

#endif // LOCKABLESTATEUPDATEABSTRACTMESSAGE_H