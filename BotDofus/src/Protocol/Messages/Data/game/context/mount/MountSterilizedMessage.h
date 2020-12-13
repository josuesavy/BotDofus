#ifndef MOUNTSTERILIZEDMESSAGE_H
#define MOUNTSTERILIZEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountSterilizedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountSterilizedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountSterilizedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountSterilizedMessage(FuncTree tree);
  MountSterilizedMessage();

  int mountId;

private:
  void _mountIdFunc(Reader *input);
};

#endif // MOUNTSTERILIZEDMESSAGE_H