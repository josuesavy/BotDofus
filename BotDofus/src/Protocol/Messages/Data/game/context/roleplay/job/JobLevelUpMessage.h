#ifndef JOBLEVELUPMESSAGE_H
#define JOBLEVELUPMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobDescription.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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