#include "ShortcutObjectIdolsPreset.h"

void ShortcutObjectIdolsPreset::serialize(Writer *output)
{
  this->serializeAs_ShortcutObjectIdolsPreset(output);
}

void ShortcutObjectIdolsPreset::serializeAs_ShortcutObjectIdolsPreset(Writer *output)
{
  ShortcutObject::serializeAs_ShortcutObject(output);
  output->writeShort((short)this->presetId);
}

void ShortcutObjectIdolsPreset::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutObjectIdolsPreset(input);
}

void ShortcutObjectIdolsPreset::deserializeAs_ShortcutObjectIdolsPreset(Reader *input)
{
  ShortcutObject::deserialize(input);
  this->_presetIdFunc(input);
}

void ShortcutObjectIdolsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutObjectIdolsPreset(tree);
}

void ShortcutObjectIdolsPreset::deserializeAsyncAs_ShortcutObjectIdolsPreset(FuncTree tree)
{
  ShortcutObject::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutObjectIdolsPreset::_presetIdFunc, this, std::placeholders::_1));
}

void ShortcutObjectIdolsPreset::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

ShortcutObjectIdolsPreset::ShortcutObjectIdolsPreset()
{
  m_types<<ClassEnum::SHORTCUTOBJECTIDOLSPRESET;
}

bool ShortcutObjectIdolsPreset::operator==(const ShortcutObjectIdolsPreset &compared)
{
  if(presetId == compared.presetId)
  return true;
  
  return false;
}

