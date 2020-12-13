#ifndef MOUNTEMOTEICONUSEDOKMESSAGE_H
#define MOUNTEMOTEICONUSEDOKMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountEmoteIconUsedOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountEmoteIconUsedOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountEmoteIconUsedOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountEmoteIconUsedOkMessage(FuncTree tree);
  MountEmoteIconUsedOkMessage();

  int mountId;
  uint reactionType;

private:
  void _mountIdFunc(Reader *input);
  void _reactionTypeFunc(Reader *input);
};

#endif // MOUNTEMOTEICONUSEDOKMESSAGE_H