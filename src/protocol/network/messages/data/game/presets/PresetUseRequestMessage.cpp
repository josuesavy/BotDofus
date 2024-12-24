#include "PresetUseRequestMessage.h"

void PresetUseRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PresetUseRequestMessage(output);
}

void PresetUseRequestMessage::serializeAs_PresetUseRequestMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
}

void PresetUseRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetUseRequestMessage(input);
}

void PresetUseRequestMessage::deserializeAs_PresetUseRequestMessage(Reader *input)
{
  this->_presetIdFunc(input);
}

void PresetUseRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetUseRequestMessage(tree);
}

void PresetUseRequestMessage::deserializeAsyncAs_PresetUseRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetUseRequestMessage::_presetIdFunc, this, std::placeholders::_1));
}

void PresetUseRequestMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

PresetUseRequestMessage::PresetUseRequestMessage()
{
  m_type = MessageEnum::PRESETUSEREQUESTMESSAGE;
}

