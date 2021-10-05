#ifndef JOBEXPERIENCEMULTIUPDATEMESSAGE_H
#define JOBEXPERIENCEMULTIUPDATEMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/job/JobExperience.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class JobExperienceMultiUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobExperienceMultiUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobExperienceMultiUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobExperienceMultiUpdateMessage(FuncTree tree);
  JobExperienceMultiUpdateMessage();

  QList<JobExperience> experiencesUpdate;

private:
  void _experiencesUpdatetreeFunc(Reader *input);
  void _experiencesUpdateFunc(Reader *input);

  FuncTree _experiencesUpdatetree;
};

#endif // JOBEXPERIENCEMULTIUPDATEMESSAGE_H