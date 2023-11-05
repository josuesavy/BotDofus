#include "AddTaxCollectorOrderedSpellMessage.h"

void AddTaxCollectorOrderedSpellMessage::serialize(Writer *output)
{
  this->serializeAs_AddTaxCollectorOrderedSpellMessage(output);
}

void AddTaxCollectorOrderedSpellMessage::serializeAs_AddTaxCollectorOrderedSpellMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AddTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  this->spell.serializeAs_TaxCollectorOrderedSpell(output);
}

void AddTaxCollectorOrderedSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_AddTaxCollectorOrderedSpellMessage(input);
}

void AddTaxCollectorOrderedSpellMessage::deserializeAs_AddTaxCollectorOrderedSpellMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
  this->spell = TaxCollectorOrderedSpell();
  this->spell.deserialize(input);
}

void AddTaxCollectorOrderedSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AddTaxCollectorOrderedSpellMessage(tree);
}

void AddTaxCollectorOrderedSpellMessage::deserializeAsyncAs_AddTaxCollectorOrderedSpellMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AddTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  this->_spelltree = tree.addChild(std::bind(&AddTaxCollectorOrderedSpellMessage::_spelltreeFunc, this, std::placeholders::_1));
}

void AddTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AddTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of AddTaxCollectorOrderedSpellMessage.taxCollectorId.";
  }
}

void AddTaxCollectorOrderedSpellMessage::_spelltreeFunc(Reader *input)
{
  this->spell = TaxCollectorOrderedSpell();
  this->spell.deserializeAsync(this->_spelltree);
}

AddTaxCollectorOrderedSpellMessage::AddTaxCollectorOrderedSpellMessage()
{
  m_type = MessageEnum::ADDTAXCOLLECTORORDEREDSPELLMESSAGE;
}

