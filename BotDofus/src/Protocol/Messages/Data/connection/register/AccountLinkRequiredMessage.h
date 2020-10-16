#ifndef ACCOUNTLINKREQUIREDMESSAGE_H
#define ACCOUNTLINKREQUIREDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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