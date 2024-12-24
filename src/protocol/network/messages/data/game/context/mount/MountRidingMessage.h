#ifndef MOUNTRIDINGMESSAGE_H
#define MOUNTRIDINGMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MountRidingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountRidingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountRidingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountRidingMessage(FuncTree tree);
  MountRidingMessage();

  bool isRiding;
  bool isAutopilot;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // MOUNTRIDINGMESSAGE_H