#ifndef ACTIVITYHIDEREQUESTMESSAGE_H
#define ACTIVITYHIDEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ActivityHideRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActivityHideRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActivityHideRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActivityHideRequestMessage(FuncTree tree);
  ActivityHideRequestMessage();

  uint activityId;

private:
  void _activityIdFunc(Reader *input);
};

#endif // ACTIVITYHIDEREQUESTMESSAGE_H