#include "TaxCollectorPresetSpellUpdatedMessage.h"

void TaxCollectorPresetSpellUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorPresetSpellUpdatedMessage(output);
}

void TaxCollectorPresetSpellUpdatedMessage::serializeAs_TaxCollectorPresetSpellUpdatedMessage(Writer *output)
{
  this->presetId.serializeAs_uuid(output);
  output->writeShort((short)this->taxCollectorSpells.size());
  for(uint _i2 = 0; _i2 < this->taxCollectorSpells.size(); _i2++)
  {
    (this->taxCollectorSpells[_i2]).serializeAs_TaxCollectorOrderedSpell(output);
  }
}

void TaxCollectorPresetSpellUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorPresetSpellUpdatedMessage(input);
}

void TaxCollectorPresetSpellUpdatedMessage::deserializeAs_TaxCollectorPresetSpellUpdatedMessage(Reader *input)
{
  TaxCollectorOrderedSpell _item2 ;
  this->presetId = uuid();
  this->presetId.deserialize(input);
  uint _taxCollectorSpellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _taxCollectorSpellsLen; _i2++)
  {
    _item2 = TaxCollectorOrderedSpell();
    _item2.deserialize(input);
    this->taxCollectorSpells.append(_item2);
  }
}

void TaxCollectorPresetSpellUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorPresetSpellUpdatedMessage(tree);
}

void TaxCollectorPresetSpellUpdatedMessage::deserializeAsyncAs_TaxCollectorPresetSpellUpdatedMessage(FuncTree tree)
{
  this->_presetIdtree = tree.addChild(std::bind(&TaxCollectorPresetSpellUpdatedMessage::_presetIdtreeFunc, this, std::placeholders::_1));
  this->_taxCollectorSpellstree = tree.addChild(std::bind(&TaxCollectorPresetSpellUpdatedMessage::_taxCollectorSpellstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorPresetSpellUpdatedMessage::_presetIdtreeFunc(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserializeAsync(this->_presetIdtree);
}

void TaxCollectorPresetSpellUpdatedMessage::_taxCollectorSpellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_taxCollectorSpellstree.addChild(std::bind(&TaxCollectorPresetSpellUpdatedMessage::_taxCollectorSpellsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorPresetSpellUpdatedMessage::_taxCollectorSpellsFunc(Reader *input)
{
  TaxCollectorOrderedSpell _item = TaxCollectorOrderedSpell();
  _item.deserialize(input);
  this->taxCollectorSpells.append(_item);
}

TaxCollectorPresetSpellUpdatedMessage::TaxCollectorPresetSpellUpdatedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE;
}

