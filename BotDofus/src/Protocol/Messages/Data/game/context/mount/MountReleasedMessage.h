#ifndef MOUNTRELEASEDMESSAGE_H
#define MOUNTRELEASEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountReleasedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountReleasedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountReleasedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountReleasedMessage(FuncTree tree);
  MountReleasedMessage();

  int mountId;

private:
  void _mountIdFunc(Reader *input);
};

#endif // MOUNTRELEASEDMESSAGE_H