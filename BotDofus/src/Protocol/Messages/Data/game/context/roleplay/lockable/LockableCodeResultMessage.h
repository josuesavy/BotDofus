#ifndef LOCKABLECODERESULTMESSAGE_H
#define LOCKABLECODERESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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