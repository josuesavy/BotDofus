#ifndef JOBCRAFTERDIRECTORYLISTMESSAGE_H
#define JOBCRAFTERDIRECTORYLISTMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class JobCrafterDirectoryListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryListMessage(FuncTree tree);
  JobCrafterDirectoryListMessage();

  QList<QSharedPointer<JobCrafterDirectoryListEntry>> listEntries;

private:
  void _listEntriestreeFunc(Reader *input);
  void _listEntriesFunc(Reader *input);

  FuncTree _listEntriestree;
};

#endif // JOBCRAFTERDIRECTORYLISTMESSAGE_H