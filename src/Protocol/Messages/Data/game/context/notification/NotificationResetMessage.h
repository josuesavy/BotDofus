#ifndef NOTIFICATIONRESETMESSAGE_H
#define NOTIFICATIONRESETMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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