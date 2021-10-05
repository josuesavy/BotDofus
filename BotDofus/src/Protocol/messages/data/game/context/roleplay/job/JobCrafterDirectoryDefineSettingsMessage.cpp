#include "JobCrafterDirectoryDefineSettingsMessage.h"

void JobCrafterDirectoryDefineSettingsMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryDefineSettingsMessage(output);
}

void JobCrafterDirectoryDefineSettingsMessage::serializeAs_JobCrafterDirectoryDefineSettingsMessage(Writer *output)
{
  this->settings.serializeAs_JobCrafterDirectorySettings(output);
}

void JobCrafterDirectoryDefineSettingsMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryDefineSettingsMessage(input);
}

void JobCrafterDirectoryDefineSettingsMessage::deserializeAs_JobCrafterDirectoryDefineSettingsMessage(Reader *input)
{
  this->settings = JobCrafterDirectorySettings();
  this->settings.deserialize(input);
}

void JobCrafterDirectoryDefineSettingsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryDefineSettingsMessage(tree);
}

void JobCrafterDirectoryDefineSettingsMessage::deserializeAsyncAs_JobCrafterDirectoryDefineSettingsMessage(FuncTree tree)
{
  this->_settingstree = tree.addChild(std::bind(&JobCrafterDirectoryDefineSettingsMessage::_settingstreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryDefineSettingsMessage::_settingstreeFunc(Reader *input)
{
  this->settings = JobCrafterDirectorySettings();
  this->settings.deserializeAsync(this->_settingstree);
}

JobCrafterDirectoryDefineSettingsMessage::JobCrafterDirectoryDefineSettingsMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE;
}

