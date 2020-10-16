#ifndef LOCKABLECHANGECODEMESSAGE_H
#define LOCKABLECHANGECODEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class LockableChangeCodeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableChangeCodeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableChangeCodeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableChangeCodeMessage(FuncTree tree);
  LockableChangeCodeMessage();

  QString code;

private:
  void _codeFunc(Reader *input);
};

#endif // LOCKABLECHANGECODEMESSAGE_H