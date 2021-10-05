#include "ItemDurability.h"

void ItemDurability::serialize(Writer *output)
{
  this->serializeAs_ItemDurability(output);
}

void ItemDurability::serializeAs_ItemDurability(Writer *output)
{
  output->writeShort((short)this->durability);
  output->writeShort((short)this->durabilityMax);
}

void ItemDurability::deserialize(Reader *input)
{
  this->deserializeAs_ItemDurability(input);
}

void ItemDurability::deserializeAs_ItemDurability(Reader *input)
{
  this->_durabilityFunc(input);
  this->_durabilityMaxFunc(input);
}

void ItemDurability::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ItemDurability(tree);
}

void ItemDurability::deserializeAsyncAs_ItemDurability(FuncTree tree)
{
  tree.addChild(std::bind(&ItemDurability::_durabilityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ItemDurability::_durabilityMaxFunc, this, std::placeholders::_1));
}

void ItemDurability::_durabilityFunc(Reader *input)
{
  this->durability = input->readShort();
}

void ItemDurability::_durabilityMaxFunc(Reader *input)
{
  this->durabilityMax = input->readShort();
}

ItemDurability::ItemDurability()
{
  m_types<<ClassEnum::ITEMDURABILITY;
}

bool ItemDurability::operator==(const ItemDurability &compared)
{
  if(durability == compared.durability)
  if(durabilityMax == compared.durabilityMax)
  return true;
  
  return false;
}

