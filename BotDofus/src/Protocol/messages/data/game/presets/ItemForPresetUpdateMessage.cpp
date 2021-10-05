#include "ItemForPresetUpdateMessage.h"

void ItemForPresetUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_ItemForPresetUpdateMessage(output);
}

void ItemForPresetUpdateMessage::serializeAs_ItemForPresetUpdateMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  this->presetItem.serializeAs_ItemForPreset(output);
}

void ItemForPresetUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ItemForPresetUpdateMessage(input);
}

void ItemForPresetUpdateMessage::deserializeAs_ItemForPresetUpdateMessage(Reader *input)
{
  this->_presetIdFunc(input);
  this->presetItem = ItemForPreset();
  this->presetItem.deserialize(input);
}

void ItemForPresetUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ItemForPresetUpdateMessage(tree);
}

void ItemForPresetUpdateMessage::deserializeAsyncAs_ItemForPresetUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ItemForPresetUpdateMessage::_presetIdFunc, this, std::placeholders::_1));
  this->_presetItemtree = tree.addChild(std::bind(&ItemForPresetUpdateMessage::_presetItemtreeFunc, this, std::placeholders::_1));
}

void ItemForPresetUpdateMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void ItemForPresetUpdateMessage::_presetItemtreeFunc(Reader *input)
{
  this->presetItem = ItemForPreset();
  this->presetItem.deserializeAsync(this->_presetItemtree);
}

ItemForPresetUpdateMessage::ItemForPresetUpdateMessage()
{
  m_type = MessageEnum::ITEMFORPRESETUPDATEMESSAGE;
}

