#ifndef JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class JobCrafterDirectoryDefineSettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryDefineSettingsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryDefineSettingsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryDefineSettingsMessage(FuncTree tree);
  JobCrafterDirectoryDefineSettingsMessage();

  JobCrafterDirectorySettings settings;

private:
  void _settingstreeFunc(Reader *input);

  FuncTree _settingstree;
};

#endif // JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H