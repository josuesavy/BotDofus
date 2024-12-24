#ifndef MOUNTDATAERRORMESSAGE_H
#define MOUNTDATAERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MountDataErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountDataErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountDataErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountDataErrorMessage(FuncTree tree);
  MountDataErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // MOUNTDATAERRORMESSAGE_H