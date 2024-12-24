#ifndef PAUSEDIALOGMESSAGE_H
#define PAUSEDIALOGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PauseDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PauseDialogMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PauseDialogMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PauseDialogMessage(FuncTree tree);
  PauseDialogMessage();

  uint dialogType;

private:
  void _dialogTypeFunc(Reader *input);
};

#endif // PAUSEDIALOGMESSAGE_H