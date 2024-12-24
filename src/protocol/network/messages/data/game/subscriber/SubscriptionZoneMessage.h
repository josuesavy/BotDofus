#ifndef SUBSCRIPTIONZONEMESSAGE_H
#define SUBSCRIPTIONZONEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SubscriptionZoneMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SubscriptionZoneMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SubscriptionZoneMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SubscriptionZoneMessage(FuncTree tree);
  SubscriptionZoneMessage();

  bool active;

private:
  void _activeFunc(Reader *input);
};

#endif // SUBSCRIPTIONZONEMESSAGE_H