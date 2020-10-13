#ifndef JOBBOOKSUBSCRIPTIONMESSAGE_H
#define JOBBOOKSUBSCRIPTIONMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobBookSubscription.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobBookSubscriptionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobBookSubscriptionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobBookSubscriptionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobBookSubscriptionMessage(FuncTree tree);
  JobBookSubscriptionMessage();

  QList<JobBookSubscription> subscriptions;

private:
  void _subscriptionstreeFunc(Reader *input);
  void _subscriptionsFunc(Reader *input);

  FuncTree _subscriptionstree;
};

#endif // JOBBOOKSUBSCRIPTIONMESSAGE_H