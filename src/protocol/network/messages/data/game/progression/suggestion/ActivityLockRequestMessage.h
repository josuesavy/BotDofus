#ifndef ACTIVITYLOCKREQUESTMESSAGE_H
#define ACTIVITYLOCKREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ActivityLockRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActivityLockRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActivityLockRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActivityLockRequestMessage(FuncTree tree);
  ActivityLockRequestMessage();

  uint activityId;
  bool lock;

private:
  void _activityIdFunc(Reader *input);
  void _lockFunc(Reader *input);
};

#endif // ACTIVITYLOCKREQUESTMESSAGE_H