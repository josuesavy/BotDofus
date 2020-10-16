#ifndef MOUNTUNSETMESSAGE_H
#define MOUNTUNSETMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MountUnSetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountUnSetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountUnSetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountUnSetMessage(FuncTree tree);
  MountUnSetMessage();
};

#endif // MOUNTUNSETMESSAGE_H