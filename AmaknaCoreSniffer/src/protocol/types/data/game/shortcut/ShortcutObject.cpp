#include "ShortcutObject.h"

void ShortcutObject::serialize(Writer *output)
{
  this->serializeAs_ShortcutObject(output);
}

void ShortcutObject::serializeAs_ShortcutObject(Writer *output)
{
  Shortcut::serializeAs_Shortcut(output);
}

void ShortcutObject::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutObject(input);
}

void ShortcutObject::deserializeAs_ShortcutObject(Reader *input)
{
  Shortcut::deserialize(input);
}

void ShortcutObject::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutObject(tree);
}

void ShortcutObject::deserializeAsyncAs_ShortcutObject(FuncTree tree)
{
  Shortcut::deserializeAsync(tree);
}

ShortcutObject::ShortcutObject()
{
  m_types<<ClassEnum::SHORTCUTOBJECT;
}

bool ShortcutObject::operator==(const ShortcutObject &compared)
{
  return true;
}

