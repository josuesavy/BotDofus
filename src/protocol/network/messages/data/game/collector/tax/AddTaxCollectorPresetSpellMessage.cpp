#include "AddTaxCollectorPresetSpellMessage.h"

void AddTaxCollectorPresetSpellMessage::serialize(Writer *output)
{
  this->serializeAs_AddTaxCollectorPresetSpellMessage(output);
}

void AddTaxCollectorPresetSpellMessage::serializeAs_AddTaxCollectorPresetSpellMessage(Writer *output)
{
  this->presetId.serializeAs_uuid(output);
  this->spell.serializeAs_TaxCollectorOrderedSpell(output);
}

void AddTaxCollectorPresetSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_AddTaxCollectorPresetSpellMessage(input);
}

void AddTaxCollectorPresetSpellMessage::deserializeAs_AddTaxCollectorPresetSpellMessage(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserialize(input);
  this->spell = TaxCollectorOrderedSpell();
  this->spell.deserialize(input);
}

void AddTaxCollectorPresetSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AddTaxCollectorPresetSpellMessage(tree);
}

void AddTaxCollectorPresetSpellMessage::deserializeAsyncAs_AddTaxCollectorPresetSpellMessage(FuncTree tree)
{
  this->_presetIdtree = tree.addChild(std::bind(&AddTaxCollectorPresetSpellMessage::_presetIdtreeFunc, this, std::placeholders::_1));
  this->_spelltree = tree.addChild(std::bind(&AddTaxCollectorPresetSpellMessage::_spelltreeFunc, this, std::placeholders::_1));
}

void AddTaxCollectorPresetSpellMessage::_presetIdtreeFunc(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserializeAsync(this->_presetIdtree);
}

void AddTaxCollectorPresetSpellMessage::_spelltreeFunc(Reader *input)
{
  this->spell = TaxCollectorOrderedSpell();
  this->spell.deserializeAsync(this->_spelltree);
}

AddTaxCollectorPresetSpellMessage::AddTaxCollectorPresetSpellMessage()
{
  m_type = MessageEnum::ADDTAXCOLLECTORPRESETSPELLMESSAGE;
}

