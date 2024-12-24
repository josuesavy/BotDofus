#ifndef JOBCRAFTERDIRECTORYREMOVEMESSAGE_H
#define JOBCRAFTERDIRECTORYREMOVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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