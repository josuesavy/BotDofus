#ifndef JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H
#define JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/job/JobExperience.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/job/JobExperienceUpdateMessage.h"

class JobExperienceOtherPlayerUpdateMessage : public JobExperienceUpdateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobExperienceOtherPlayerUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobExperienceOtherPlayerUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobExperienceOtherPlayerUpdateMessage(FuncTree tree);
  JobExperienceOtherPlayerUpdateMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H