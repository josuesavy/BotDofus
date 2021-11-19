#ifndef JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H
#define JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class JobCrafterDirectoryEntryRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryEntryRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryEntryRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryEntryRequestMessage(FuncTree tree);
  JobCrafterDirectoryEntryRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H