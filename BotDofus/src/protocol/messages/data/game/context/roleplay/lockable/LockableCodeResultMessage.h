#ifndef LOCKABLECODERESULTMESSAGE_H
#define LOCKABLECODERESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class LockableCodeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableCodeResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableCodeResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableCodeResultMessage(FuncTree tree);
  LockableCodeResultMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // LOCKABLECODERESULTMESSAGE_H