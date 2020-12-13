#ifndef MAILSTATUSMESSAGE_H
#define MAILSTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MailStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MailStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MailStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MailStatusMessage(FuncTree tree);
  MailStatusMessage();

  uint unread;
  uint total;

private:
  void _unreadFunc(Reader *input);
  void _totalFunc(Reader *input);
};

#endif // MAILSTATUSMESSAGE_H