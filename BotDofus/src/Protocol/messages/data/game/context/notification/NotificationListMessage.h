#ifndef NOTIFICATIONLISTMESSAGE_H
#define NOTIFICATIONLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NotificationListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NotificationListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NotificationListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NotificationListMessage(FuncTree tree);
  NotificationListMessage();

  QList<int> flags;

private:
  void _flagstreeFunc(Reader *input);
  void _flagsFunc(Reader *input);

  FuncTree _flagstree;
};

#endif // NOTIFICATIONLISTMESSAGE_H