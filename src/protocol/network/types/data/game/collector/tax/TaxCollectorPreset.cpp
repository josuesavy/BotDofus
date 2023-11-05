#include "TaxCollectorPreset.h"

void TaxCollectorPreset::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorPreset(output);
}

void TaxCollectorPreset::serializeAs_TaxCollectorPreset(Writer *output)
{
  this->presetId.serializeAs_uuid(output);
  output->writeShort((short)this->spells.size());
  for(uint _i2 = 0; _i2 < this->spells.size(); _i2++)
  {
    (this->spells[_i2]).serializeAs_TaxCollectorOrderedSpell(output);
  }
  this->characteristics.serializeAs_CharacterCharacteristics(output);
}

void TaxCollectorPreset::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorPreset(input);
}

void TaxCollectorPreset::deserializeAs_TaxCollectorPreset(Reader *input)
{
   _item2 ;
  this->presetId = uuid();
  this->presetId.deserialize(input);
  uint _spellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _spellsLen; _i2++)
  {
    _item2 = new com.ankamagames.dofus.network.types.game.collector.tax.TaxCollectorOrderedSpell();
    _item2.deserialize(input);
    this->spells.append(_item2);
  }
  this->characteristics = CharacterCharacteristics();
  this->characteristics.deserialize(input);
}

void TaxCollectorPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorPreset(tree);
}

void TaxCollectorPreset::deserializeAsyncAs_TaxCollectorPreset(FuncTree tree)
{
  this->_presetIdtree = tree.addChild(std::bind(&TaxCollectorPreset::_presetIdtreeFunc, this, std::placeholders::_1));
  this->_spellstree = tree.addChild(std::bind(&TaxCollectorPreset::_spellstreeFunc, this, std::placeholders::_1));
  this->_characteristicstree = tree.addChild(std::bind(&TaxCollectorPreset::_characteristicstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorPreset::_presetIdtreeFunc(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserializeAsync(this->_presetIdtree);
}

void TaxCollectorPreset::_spellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&TaxCollectorPreset::_spellsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorPreset::_spellsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.collector.tax.TaxCollectorOrderedSpell();
  _item.deserialize(input);
  this->spells.append(_item);
}

void TaxCollectorPreset::_characteristicstreeFunc(Reader *input)
{
  this->characteristics = CharacterCharacteristics();
  this->characteristics.deserializeAsync(this->_characteristicstree);
}

TaxCollectorPreset::TaxCollectorPreset()
{
  m_types<<ClassEnum::TAXCOLLECTORPRESET;
}

bool TaxCollectorPreset::operator==(const TaxCollectorPreset &compared)
{
  if(presetId == compared.presetId)
  if(spells == compared.spells)
  if(characteristics == compared.characteristics)
  if(_presetIdtree == compared._presetIdtree)
  if(_spellstree == compared._spellstree)
  if(_characteristicstree == compared._characteristicstree)
  return true;
  
  return false;
}

