#ifndef JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H
#define JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class JobCrafterDirectoryListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryListRequestMessage(FuncTree tree);
  JobCrafterDirectoryListRequestMessage();

  uint jobId;

private:
  void _jobIdFunc(Reader *input);
};

#endif // JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H