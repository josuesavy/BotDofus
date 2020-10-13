#ifndef JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H
#define JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/job/JobAllowMultiCraftRequestMessage.h"

class JobMultiCraftAvailableSkillsMessage : public JobAllowMultiCraftRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobMultiCraftAvailableSkillsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobMultiCraftAvailableSkillsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobMultiCraftAvailableSkillsMessage(FuncTree tree);
  JobMultiCraftAvailableSkillsMessage();

  double playerId;
  QList<uint> skills;

private:
  void _playerIdFunc(Reader *input);
  void _skillstreeFunc(Reader *input);
  void _skillsFunc(Reader *input);

  FuncTree _skillstree;
};

#endif // JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H