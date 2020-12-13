#ifndef NEWMAILMESSAGE_H
#define NEWMAILMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/web/ankabox/MailStatusMessage.h"

class NewMailMessage : public MailStatusMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NewMailMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NewMailMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NewMailMessage(FuncTree tree);
  NewMailMessage();

  QList<uint> sendersAccountId;

private:
  void _sendersAccountIdtreeFunc(Reader *input);
  void _sendersAccountIdFunc(Reader *input);

  FuncTree _sendersAccountIdtree;
};

#endif // NEWMAILMESSAGE_H