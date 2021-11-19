#include "ForgettableSpellsPreset.h"

void ForgettableSpellsPreset::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellsPreset(output);
}

void ForgettableSpellsPreset::serializeAs_ForgettableSpellsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  this->baseSpellsPreset->serializeAs_SpellsPreset(output);
  output->writeShort((short)this->forgettableSpells.size());
  for(uint _i2 = 0; _i2 < this->forgettableSpells.size(); _i2++)
  {
    (this->forgettableSpells[_i2]).serializeAs_SpellForPreset(output);
  }
}

void ForgettableSpellsPreset::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellsPreset(input);
}

void ForgettableSpellsPreset::deserializeAs_ForgettableSpellsPreset(Reader *input)
{
  SpellForPreset _item2 ;
  Preset::deserialize(input);
  this->baseSpellsPreset = QSharedPointer<SpellsPreset>(new SpellsPreset() );
  this->baseSpellsPreset->deserialize(input);
  uint _forgettableSpellsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _forgettableSpellsLen; _i2++)
  {
    _item2 = SpellForPreset();
    _item2.deserialize(input);
    this->forgettableSpells.append(_item2);
  }
}

void ForgettableSpellsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellsPreset(tree);
}

void ForgettableSpellsPreset::deserializeAsyncAs_ForgettableSpellsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_baseSpellsPresettree = tree.addChild(std::bind(&ForgettableSpellsPreset::_baseSpellsPresettreeFunc, this, std::placeholders::_1));
  this->_forgettableSpellstree = tree.addChild(std::bind(&ForgettableSpellsPreset::_forgettableSpellstreeFunc, this, std::placeholders::_1));
}

void ForgettableSpellsPreset::_baseSpellsPresettreeFunc(Reader *input)
{
  this->baseSpellsPreset = QSharedPointer<SpellsPreset>(new SpellsPreset() );
  this->baseSpellsPreset->deserializeAsync(this->_baseSpellsPresettree);
}

void ForgettableSpellsPreset::_forgettableSpellstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_forgettableSpellstree.addChild(std::bind(&ForgettableSpellsPreset::_forgettableSpellsFunc, this, std::placeholders::_1));
  }
}

void ForgettableSpellsPreset::_forgettableSpellsFunc(Reader *input)
{
  SpellForPreset _item = SpellForPreset();
  _item.deserialize(input);
  this->forgettableSpells.append(_item);
}

ForgettableSpellsPreset::ForgettableSpellsPreset()
{
  m_types<<ClassEnum::FORGETTABLESPELLSPRESET;
}

bool ForgettableSpellsPreset::operator==(const ForgettableSpellsPreset &compared)
{
  if(baseSpellsPreset == compared.baseSpellsPreset)
  if(forgettableSpells == compared.forgettableSpells)
  if(_baseSpellsPresettree == compared._baseSpellsPresettree)
  if(_forgettableSpellstree == compared._forgettableSpellstree)
  return true;
  
  return false;
}

