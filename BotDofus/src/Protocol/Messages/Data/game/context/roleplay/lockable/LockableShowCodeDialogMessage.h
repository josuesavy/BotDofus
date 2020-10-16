#ifndef LOCKABLESHOWCODEDIALOGMESSAGE_H
#define LOCKABLESHOWCODEDIALOGMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class LockableShowCodeDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LockableShowCodeDialogMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LockableShowCodeDialogMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LockableShowCodeDialogMessage(FuncTree tree);
  LockableShowCodeDialogMessage();

  bool changeOrUse;
  uint codeSize;

private:
  void _changeOrUseFunc(Reader *input);
  void _codeSizeFunc(Reader *input);
};

#endif // LOCKABLESHOWCODEDIALOGMESSAGE_H