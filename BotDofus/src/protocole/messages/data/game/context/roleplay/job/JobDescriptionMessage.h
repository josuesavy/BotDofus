#ifndef JOBDESCRIPTIONMESSAGE_H
#define JOBDESCRIPTIONMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/job/JobDescription.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class JobDescriptionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobDescriptionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobDescriptionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobDescriptionMessage(FuncTree tree);
  JobDescriptionMessage();

  QList<QSharedPointer<JobDescription>> jobsDescription;

private:
  void _jobsDescriptiontreeFunc(Reader *input);
  void _jobsDescriptionFunc(Reader *input);

  FuncTree _jobsDescriptiontree;
};

#endif // JOBDESCRIPTIONMESSAGE_H