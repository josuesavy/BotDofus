#include "PresetDeleteRequestMessage.h"

void PresetDeleteRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PresetDeleteRequestMessage(output);
}

void PresetDeleteRequestMessage::serializeAs_PresetDeleteRequestMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
}

void PresetDeleteRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetDeleteRequestMessage(input);
}

void PresetDeleteRequestMessage::deserializeAs_PresetDeleteRequestMessage(Reader *input)
{
  this->_presetIdFunc(input);
}

void PresetDeleteRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetDeleteRequestMessage(tree);
}

void PresetDeleteRequestMessage::deserializeAsyncAs_PresetDeleteRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetDeleteRequestMessage::_presetIdFunc, this, std::placeholders::_1));
}

void PresetDeleteRequestMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

PresetDeleteRequestMessage::PresetDeleteRequestMessage()
{
  m_type = MessageEnum::PRESETDELETEREQUESTMESSAGE;
}

