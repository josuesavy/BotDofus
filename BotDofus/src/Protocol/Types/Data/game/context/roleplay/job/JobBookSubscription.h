#ifndef JOBBOOKSUBSCRIPTION_H
#define JOBBOOKSUBSCRIPTION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class JobBookSubscription : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobBookSubscription(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobBookSubscription(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobBookSubscription(FuncTree tree);
  JobBookSubscription();
  bool operator==(const JobBookSubscription &compared);

  uint jobId;
  bool subscribed;

private:
  void _jobIdFunc(Reader *input);
  void _subscribedFunc(Reader *input);
};

#endif // JOBBOOKSUBSCRIPTION_H