#ifndef NOTIFICATIONRESETMESSAGE_H
#define NOTIFICATIONRESETMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NotificationResetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NotificationResetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NotificationResetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NotificationResetMessage(FuncTree tree);
  NotificationResetMessage();
};

#endif // NOTIFICATIONRESETMESSAGE_H