#include "TaxCollectorOrderedSpell.h"

void TaxCollectorOrderedSpell::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorOrderedSpell(output);
}

void TaxCollectorOrderedSpell::serializeAs_TaxCollectorOrderedSpell(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpell -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarInt((int)this->spellId);
  if(this->slot < 0 || this->slot > 5)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpell -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void TaxCollectorOrderedSpell::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorOrderedSpell(input);
}

void TaxCollectorOrderedSpell::deserializeAs_TaxCollectorOrderedSpell(Reader *input)
{
  this->_spellIdFunc(input);
  this->_slotFunc(input);
}

void TaxCollectorOrderedSpell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorOrderedSpell(tree);
}

void TaxCollectorOrderedSpell::deserializeAsyncAs_TaxCollectorOrderedSpell(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorOrderedSpell::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorOrderedSpell::_slotFunc, this, std::placeholders::_1));
}

void TaxCollectorOrderedSpell::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhInt();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpell -"<<"Forbidden value (" << this->spellId << ") on element of TaxCollectorOrderedSpell.spellId.";
  }
}

void TaxCollectorOrderedSpell::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0 || this->slot > 5)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpell -"<<"Forbidden value (" << this->slot << ") on element of TaxCollectorOrderedSpell.slot.";
  }
}

TaxCollectorOrderedSpell::TaxCollectorOrderedSpell()
{
  m_types<<ClassEnum::TAXCOLLECTORORDEREDSPELL;
}

bool TaxCollectorOrderedSpell::operator==(const TaxCollectorOrderedSpell &compared)
{
  if(spellId == compared.spellId)
  if(slot == compared.slot)
  return true;
  
  return false;
}

