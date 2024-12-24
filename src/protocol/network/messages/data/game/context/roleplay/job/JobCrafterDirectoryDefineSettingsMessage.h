#ifndef JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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