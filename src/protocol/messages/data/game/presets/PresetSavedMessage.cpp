#include "PresetSavedMessage.h"

void PresetSavedMessage::serialize(Writer *output)
{
  this->serializeAs_PresetSavedMessage(output);
}

void PresetSavedMessage::serializeAs_PresetSavedMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  output->writeShort((short)this->preset->getTypes().last());
  this->preset->serialize(output);
}

void PresetSavedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetSavedMessage(input);
}

void PresetSavedMessage::deserializeAs_PresetSavedMessage(Reader *input)
{
  this->_presetIdFunc(input);
  uint _id2 = input->readUShort();
  this->preset = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id2));
  this->preset->deserialize(input);
}

void PresetSavedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetSavedMessage(tree);
}

void PresetSavedMessage::deserializeAsyncAs_PresetSavedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetSavedMessage::_presetIdFunc, this, std::placeholders::_1));
  this->_presettree = tree.addChild(std::bind(&PresetSavedMessage::_presettreeFunc, this, std::placeholders::_1));
}

void PresetSavedMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void PresetSavedMessage::_presettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->preset = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id));
  this->preset->deserializeAsync(this->_presettree);
}

PresetSavedMessage::PresetSavedMessage()
{
  m_type = MessageEnum::PRESETSAVEDMESSAGE;
}

