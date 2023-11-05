#include "SpellsPreset.h"

void SpellsPreset::serialize(Writer *output)
{
  this->serializeAs_SpellsPreset(output);
}

void SpellsPreset::serializeAs_SpellsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  output->writeShort((short)this->spells.size());
  for(uint _i1 = 0; _i1 < this->spells.size(); _i1++)
  {
    (this->spells[_i1]).serializeAs_SpellForPreset(output);
  }
}

void SpellsPreset::deserialize(Reader *input)
{
  this->deserializeAs_SpellsPreset(input);
}

void SpellsPreset::deserializeAs_SpellsPreset(Reader *input)
{
   _item1 ;
  Preset::deserialize(input);
  uint _spellsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _spellsLen; _i1++)
  {
    _item1 = new com.ankamagames.dofus.network.types.game.presets.SpellForPreset();
    _item1.deserialize(input);
    this->spells.append(_item1);
  }
}

void SpellsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellsPreset(tree);
}

void SpellsPreset::deserializeAsyncAs_SpellsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_spellstree = tree.addChild(std::bind(&SpellsPreset::_spellstreeFunc, this, std::placeholders::_1));
}

void SpellsPreset::_spellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&SpellsPreset::_spellsFunc, this, std::placeholders::_1));
  }
}

void SpellsPreset::_spellsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.presets.SpellForPreset();
  _item.deserialize(input);
  this->spells.append(_item);
}

SpellsPreset::SpellsPreset()
{
  m_types<<ClassEnum::SPELLSPRESET;
}

bool SpellsPreset::operator==(const SpellsPreset &compared)
{
  if(spells == compared.spells)
  if(_spellstree == compared._spellstree)
  return true;
  
  return false;
}

