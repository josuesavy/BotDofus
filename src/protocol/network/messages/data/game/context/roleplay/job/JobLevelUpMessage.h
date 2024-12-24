#ifndef JOBLEVELUPMESSAGE_H
#define JOBLEVELUPMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobDescription.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class JobLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobLevelUpMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobLevelUpMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobLevelUpMessage(FuncTree tree);
  JobLevelUpMessage();

  uint newLevel;
  QSharedPointer<JobDescription> jobsDescription;

private:
  void _newLevelFunc(Reader *input);
  void _jobsDescriptiontreeFunc(Reader *input);

  FuncTree _jobsDescriptiontree;
};

#endif // JOBLEVELUPMESSAGE_H