#include "ShortcutObjectItem.h"

void ShortcutObjectItem::serialize(Writer *output)
{
  this->serializeAs_ShortcutObjectItem(output);
}

void ShortcutObjectItem::serializeAs_ShortcutObjectItem(Writer *output)
{
  ShortcutObject::serializeAs_ShortcutObject(output);
  output->writeInt((int)this->itemUID);
  output->writeInt((int)this->itemGID);
}

void ShortcutObjectItem::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutObjectItem(input);
}

void ShortcutObjectItem::deserializeAs_ShortcutObjectItem(Reader *input)
{
  ShortcutObject::deserialize(input);
  this->_itemUIDFunc(input);
  this->_itemGIDFunc(input);
}

void ShortcutObjectItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutObjectItem(tree);
}

void ShortcutObjectItem::deserializeAsyncAs_ShortcutObjectItem(FuncTree tree)
{
  ShortcutObject::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutObjectItem::_itemUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShortcutObjectItem::_itemGIDFunc, this, std::placeholders::_1));
}

void ShortcutObjectItem::_itemUIDFunc(Reader *input)
{
  this->itemUID = input->readInt();
}

void ShortcutObjectItem::_itemGIDFunc(Reader *input)
{
  this->itemGID = input->readInt();
}

ShortcutObjectItem::ShortcutObjectItem()
{
  m_types<<ClassEnum::SHORTCUTOBJECTITEM;
}

bool ShortcutObjectItem::operator==(const ShortcutObjectItem &compared)
{
  if(itemUID == compared.itemUID)
  if(itemGID == compared.itemGID)
  return true;
  
  return false;
}

