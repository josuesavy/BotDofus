#ifndef ACCOUNTLINKREQUIREDMESSAGE_H
#define ACCOUNTLINKREQUIREDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AccountLinkRequiredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountLinkRequiredMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountLinkRequiredMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountLinkRequiredMessage(FuncTree tree);
  AccountLinkRequiredMessage();
};

#endif // ACCOUNTLINKREQUIREDMESSAGE_H