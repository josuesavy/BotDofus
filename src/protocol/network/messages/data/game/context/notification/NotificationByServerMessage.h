#ifndef NOTIFICATIONBYSERVERMESSAGE_H
#define NOTIFICATIONBYSERVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NotificationByServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NotificationByServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NotificationByServerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NotificationByServerMessage(FuncTree tree);
  NotificationByServerMessage();

  uint id;
  QList<QString> parameters;
  bool forceOpen;

private:
  void _idFunc(Reader *input);
  void _parameterstreeFunc(Reader *input);
  void _parametersFunc(Reader *input);
  void _forceOpenFunc(Reader *input);

  FuncTree _parameterstree;
};

#endif // NOTIFICATIONBYSERVERMESSAGE_H