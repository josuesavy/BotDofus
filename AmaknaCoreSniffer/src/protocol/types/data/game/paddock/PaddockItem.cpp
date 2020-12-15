#include "PaddockItem.h"

void PaddockItem::serialize(Writer *output)
{
  this->serializeAs_PaddockItem(output);
}

void PaddockItem::serializeAs_PaddockItem(Writer *output)
{
  ObjectItemInRolePlay::serializeAs_ObjectItemInRolePlay(output);
  this->durability.serializeAs_ItemDurability(output);
}

void PaddockItem::deserialize(Reader *input)
{
  this->deserializeAs_PaddockItem(input);
}

void PaddockItem::deserializeAs_PaddockItem(Reader *input)
{
  ObjectItemInRolePlay::deserialize(input);
  this->durability = ItemDurability();
  this->durability.deserialize(input);
}

void PaddockItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockItem(tree);
}

void PaddockItem::deserializeAsyncAs_PaddockItem(FuncTree tree)
{
  ObjectItemInRolePlay::deserializeAsync(tree);
  this->_durabilitytree = tree.addChild(std::bind(&PaddockItem::_durabilitytreeFunc, this, std::placeholders::_1));
}

void PaddockItem::_durabilitytreeFunc(Reader *input)
{
  this->durability = ItemDurability();
  this->durability.deserializeAsync(this->_durabilitytree);
}

PaddockItem::PaddockItem()
{
  m_types<<ClassEnum::PADDOCKITEM;
}

bool PaddockItem::operator==(const PaddockItem &compared)
{
  if(durability == compared.durability)
  if(_durabilitytree == compared._durabilitytree)
  return true;
  
  return false;
}

