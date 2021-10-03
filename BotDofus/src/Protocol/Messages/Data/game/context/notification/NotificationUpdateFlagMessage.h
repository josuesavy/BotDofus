#ifndef NOTIFICATIONUPDATEFLAGMESSAGE_H
#define NOTIFICATIONUPDATEFLAGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NotificationUpdateFlagMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NotificationUpdateFlagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NotificationUpdateFlagMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NotificationUpdateFlagMessage(FuncTree tree);
  NotificationUpdateFlagMessage();

  uint index;

private:
  void _indexFunc(Reader *input);
};

#endif // NOTIFICATIONUPDATEFLAGMESSAGE_H