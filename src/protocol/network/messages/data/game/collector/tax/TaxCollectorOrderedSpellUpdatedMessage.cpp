#include "TaxCollectorOrderedSpellUpdatedMessage.h"

void TaxCollectorOrderedSpellUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorOrderedSpellUpdatedMessage(output);
}

void TaxCollectorOrderedSpellUpdatedMessage::serializeAs_TaxCollectorOrderedSpellUpdatedMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpellUpdatedMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  output->writeShort((short)this->taxCollectorSpells.size());
  for(uint _i2 = 0; _i2 < this->taxCollectorSpells.size(); _i2++)
  {
    (this->taxCollectorSpells[_i2]).serializeAs_TaxCollectorOrderedSpell(output);
  }
}

void TaxCollectorOrderedSpellUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorOrderedSpellUpdatedMessage(input);
}

void TaxCollectorOrderedSpellUpdatedMessage::deserializeAs_TaxCollectorOrderedSpellUpdatedMessage(Reader *input)
{
  TaxCollectorOrderedSpell _item2 ;
  this->_taxCollectorIdFunc(input);
  uint _taxCollectorSpellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _taxCollectorSpellsLen; _i2++)
  {
    _item2 = TaxCollectorOrderedSpell();
    _item2.deserialize(input);
    this->taxCollectorSpells.append(_item2);
  }
}

void TaxCollectorOrderedSpellUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorOrderedSpellUpdatedMessage(tree);
}

void TaxCollectorOrderedSpellUpdatedMessage::deserializeAsyncAs_TaxCollectorOrderedSpellUpdatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  this->_taxCollectorSpellstree = tree.addChild(std::bind(&TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorSpellstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorOrderedSpellUpdatedMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of TaxCollectorOrderedSpellUpdatedMessage.taxCollectorId.";
  }
}

void TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorSpellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_taxCollectorSpellstree.addChild(std::bind(&TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorSpellsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorOrderedSpellUpdatedMessage::_taxCollectorSpellsFunc(Reader *input)
{
  TaxCollectorOrderedSpell _item = TaxCollectorOrderedSpell();
  _item.deserialize(input);
  this->taxCollectorSpells.append(_item);
}

TaxCollectorOrderedSpellUpdatedMessage::TaxCollectorOrderedSpellUpdatedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORORDEREDSPELLUPDATEDMESSAGE;
}

