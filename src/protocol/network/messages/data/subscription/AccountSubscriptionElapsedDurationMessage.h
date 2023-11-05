#ifndef ACCOUNTSUBSCRIPTIONELAPSEDDURATIONMESSAGE_H
#define ACCOUNTSUBSCRIPTIONELAPSEDDURATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AccountSubscriptionElapsedDurationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountSubscriptionElapsedDurationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountSubscriptionElapsedDurationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountSubscriptionElapsedDurationMessage(FuncTree tree);
  AccountSubscriptionElapsedDurationMessage();

  double subscriptionElapsedDuration;

private:
  void _subscriptionElapsedDurationFunc(Reader *input);
};

#endif // ACCOUNTSUBSCRIPTIONELAPSEDDURATIONMESSAGE_H