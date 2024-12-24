#ifndef JOBEXPERIENCEUPDATEMESSAGE_H
#define JOBEXPERIENCEUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobExperience.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class JobExperienceUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobExperienceUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobExperienceUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobExperienceUpdateMessage(FuncTree tree);
  JobExperienceUpdateMessage();

  JobExperience experiencesUpdate;

private:
  void _experiencesUpdatetreeFunc(Reader *input);

  FuncTree _experiencesUpdatetree;
};

#endif // JOBEXPERIENCEUPDATEMESSAGE_H