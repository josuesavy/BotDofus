#ifndef LOCKABLESTATEUPDATEABSTRACTMESSAGE_H
#define LOCKABLESTATEUPDATEABSTRACTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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