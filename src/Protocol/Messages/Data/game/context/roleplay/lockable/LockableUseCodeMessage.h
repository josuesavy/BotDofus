#ifndef LOCKABLEUSECODEMESSAGE_H
#define LOCKABLEUSECODEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class LockableUseCodeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableUseCodeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableUseCodeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableUseCodeMessage(FuncTree tree);
  LockableUseCodeMessage();

  QString code;

private:
  void _codeFunc(Reader *input);
};

#endif // LOCKABLEUSECODEMESSAGE_H