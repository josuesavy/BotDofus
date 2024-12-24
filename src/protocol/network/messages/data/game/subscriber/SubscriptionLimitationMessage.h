#ifndef SUBSCRIPTIONLIMITATIONMESSAGE_H
#define SUBSCRIPTIONLIMITATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SubscriptionLimitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SubscriptionLimitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SubscriptionLimitationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SubscriptionLimitationMessage(FuncTree tree);
  SubscriptionLimitationMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // SUBSCRIPTIONLIMITATIONMESSAGE_H