#include "ShortcutObjectPreset.h"

void ShortcutObjectPreset::serialize(Writer *output)
{
  this->serializeAs_ShortcutObjectPreset(output);
}

void ShortcutObjectPreset::serializeAs_ShortcutObjectPreset(Writer *output)
{
  ShortcutObject::serializeAs_ShortcutObject(output);
  output->writeShort((short)this->presetId);
}

void ShortcutObjectPreset::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutObjectPreset(input);
}

void ShortcutObjectPreset::deserializeAs_ShortcutObjectPreset(Reader *input)
{
  ShortcutObject::deserialize(input);
  this->_presetIdFunc(input);
}

void ShortcutObjectPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutObjectPreset(tree);
}

void ShortcutObjectPreset::deserializeAsyncAs_ShortcutObjectPreset(FuncTree tree)
{
  ShortcutObject::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutObjectPreset::_presetIdFunc, this, std::placeholders::_1));
}

void ShortcutObjectPreset::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

ShortcutObjectPreset::ShortcutObjectPreset()
{
  m_types<<ClassEnum::SHORTCUTOBJECTPRESET;
}

bool ShortcutObjectPreset::operator==(const ShortcutObjectPreset &compared)
{
  if(presetId == compared.presetId)
  return true;
  
  return false;
}

