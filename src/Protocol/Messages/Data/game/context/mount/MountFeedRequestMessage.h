#ifndef MOUNTFEEDREQUESTMESSAGE_H
#define MOUNTFEEDREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MountFeedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountFeedRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountFeedRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountFeedRequestMessage(FuncTree tree);
  MountFeedRequestMessage();

  uint mountUid;
  int mountLocation;
  uint mountFoodUid;
  uint quantity;

private:
  void _mountUidFunc(Reader *input);
  void _mountLocationFunc(Reader *input);
  void _mountFoodUidFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // MOUNTFEEDREQUESTMESSAGE_H