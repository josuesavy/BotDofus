#ifndef JOBCRAFTERDIRECTORYREMOVEMESSAGE_H
#define JOBCRAFTERDIRECTORYREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobCrafterDirectoryRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryRemoveMessage(FuncTree tree);
  JobCrafterDirectoryRemoveMessage();

  uint jobId;
  double playerId;

private:
  void _jobIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // JOBCRAFTERDIRECTORYREMOVEMESSAGE_H