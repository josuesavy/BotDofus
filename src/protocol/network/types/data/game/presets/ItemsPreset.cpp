#include "ItemsPreset.h"

void ItemsPreset::serialize(Writer *output)
{
  this->serializeAs_ItemsPreset(output);
}

void ItemsPreset::serializeAs_ItemsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  output->writeShort((short)this->items.size());
  for(uint _i1 = 0; _i1 < this->items.size(); _i1++)
  {
    (this->items[_i1]).serializeAs_ItemForPreset(output);
  }
  output->writeBool(this->mountEquipped);
  this->look->serializeAs_EntityLook(output);
}

void ItemsPreset::deserialize(Reader *input)
{
  this->deserializeAs_ItemsPreset(input);
}

void ItemsPreset::deserializeAs_ItemsPreset(Reader *input)
{
  ItemForPreset _item1 ;
  Preset::deserialize(input);
  uint _itemsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _itemsLen; _i1++)
  {
    _item1 = ItemForPreset();
    _item1.deserialize(input);
    this->items.append(_item1);
  }
  this->_mountEquippedFunc(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void ItemsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ItemsPreset(tree);
}

void ItemsPreset::deserializeAsyncAs_ItemsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_itemstree = tree.addChild(std::bind(&ItemsPreset::_itemstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ItemsPreset::_mountEquippedFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&ItemsPreset::_looktreeFunc, this, std::placeholders::_1));
}

void ItemsPreset::_itemstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_itemstree.addChild(std::bind(&ItemsPreset::_itemsFunc, this, std::placeholders::_1));
  }
}

void ItemsPreset::_itemsFunc(Reader *input)
{
  ItemForPreset _item = ItemForPreset();
  _item.deserialize(input);
  this->items.append(_item);
}

void ItemsPreset::_mountEquippedFunc(Reader *input)
{
  this->mountEquipped = input->readBool();
}

void ItemsPreset::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

ItemsPreset::ItemsPreset()
{
  m_types<<ClassEnum::ITEMSPRESET;
}

bool ItemsPreset::operator==(const ItemsPreset &compared)
{
  if(items == compared.items)
  if(mountEquipped == compared.mountEquipped)
  if(look == compared.look)
  if(_itemstree == compared._itemstree)
  if(_looktree == compared._looktree)
  return true;
  
  return false;
}

