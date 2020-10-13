#ifndef JOBBOOKSUBSCRIBEREQUESTMESSAGE_H
#define JOBBOOKSUBSCRIBEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobBookSubscribeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobBookSubscribeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobBookSubscribeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobBookSubscribeRequestMessage(FuncTree tree);
  JobBookSubscribeRequestMessage();

  QList<uint> jobIds;

private:
  void _jobIdstreeFunc(Reader *input);
  void _jobIdsFunc(Reader *input);

  FuncTree _jobIdstree;
};

#endif // JOBBOOKSUBSCRIBEREQUESTMESSAGE_H