#include "JobCrafterDirectorySettingsMessage.h"

void JobCrafterDirectorySettingsMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectorySettingsMessage(output);
}

void JobCrafterDirectorySettingsMessage::serializeAs_JobCrafterDirectorySettingsMessage(Writer *output)
{
  output->writeShort((short)this->craftersSettings.size());
  for(uint _i1 = 0; _i1 < this->craftersSettings.size(); _i1++)
  {
    (this->craftersSettings[_i1]).serializeAs_JobCrafterDirectorySettings(output);
  }
}

void JobCrafterDirectorySettingsMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectorySettingsMessage(input);
}

void JobCrafterDirectorySettingsMessage::deserializeAs_JobCrafterDirectorySettingsMessage(Reader *input)
{
  JobCrafterDirectorySettings _item1 ;
  uint _craftersSettingsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _craftersSettingsLen; _i1++)
  {
    _item1 = JobCrafterDirectorySettings();
    _item1.deserialize(input);
    this->craftersSettings.append(_item1);
  }
}

void JobCrafterDirectorySettingsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectorySettingsMessage(tree);
}

void JobCrafterDirectorySettingsMessage::deserializeAsyncAs_JobCrafterDirectorySettingsMessage(FuncTree tree)
{
  this->_craftersSettingstree = tree.addChild(std::bind(&JobCrafterDirectorySettingsMessage::_craftersSettingstreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectorySettingsMessage::_craftersSettingstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_craftersSettingstree.addChild(std::bind(&JobCrafterDirectorySettingsMessage::_craftersSettingsFunc, this, std::placeholders::_1));
  }
}

void JobCrafterDirectorySettingsMessage::_craftersSettingsFunc(Reader *input)
{
  JobCrafterDirectorySettings _item = JobCrafterDirectorySettings();
  _item.deserialize(input);
  this->craftersSettings.append(_item);
}

JobCrafterDirectorySettingsMessage::JobCrafterDirectorySettingsMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYSETTINGSMESSAGE;
}

