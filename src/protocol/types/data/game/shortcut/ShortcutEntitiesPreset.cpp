#include "ShortcutEntitiesPreset.h"

void ShortcutEntitiesPreset::serialize(Writer *output)
{
  this->serializeAs_ShortcutEntitiesPreset(output);
}

void ShortcutEntitiesPreset::serializeAs_ShortcutEntitiesPreset(Writer *output)
{
  Shortcut::serializeAs_Shortcut(output);
  output->writeShort((short)this->presetId);
}

void ShortcutEntitiesPreset::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutEntitiesPreset(input);
}

void ShortcutEntitiesPreset::deserializeAs_ShortcutEntitiesPreset(Reader *input)
{
  Shortcut::deserialize(input);
  this->_presetIdFunc(input);
}

void ShortcutEntitiesPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutEntitiesPreset(tree);
}

void ShortcutEntitiesPreset::deserializeAsyncAs_ShortcutEntitiesPreset(FuncTree tree)
{
  Shortcut::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutEntitiesPreset::_presetIdFunc, this, std::placeholders::_1));
}

void ShortcutEntitiesPreset::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

ShortcutEntitiesPreset::ShortcutEntitiesPreset()
{
  m_types<<ClassEnum::SHORTCUTENTITIESPRESET;
}

bool ShortcutEntitiesPreset::operator==(const ShortcutEntitiesPreset &compared)
{
  if(presetId == compared.presetId)
  return true;
  
  return false;
}

