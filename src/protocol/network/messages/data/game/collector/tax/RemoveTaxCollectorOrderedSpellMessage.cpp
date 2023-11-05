#include "RemoveTaxCollectorOrderedSpellMessage.h"

void RemoveTaxCollectorOrderedSpellMessage::serialize(Writer *output)
{
  this->serializeAs_RemoveTaxCollectorOrderedSpellMessage(output);
}

void RemoveTaxCollectorOrderedSpellMessage::serializeAs_RemoveTaxCollectorOrderedSpellMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  if(this->slot < 0)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void RemoveTaxCollectorOrderedSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_RemoveTaxCollectorOrderedSpellMessage(input);
}

void RemoveTaxCollectorOrderedSpellMessage::deserializeAs_RemoveTaxCollectorOrderedSpellMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
  this->_slotFunc(input);
}

void RemoveTaxCollectorOrderedSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemoveTaxCollectorOrderedSpellMessage(tree);
}

void RemoveTaxCollectorOrderedSpellMessage::deserializeAsyncAs_RemoveTaxCollectorOrderedSpellMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RemoveTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemoveTaxCollectorOrderedSpellMessage::_slotFunc, this, std::placeholders::_1));
}

void RemoveTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of RemoveTaxCollectorOrderedSpellMessage.taxCollectorId.";
  }
}

void RemoveTaxCollectorOrderedSpellMessage::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->slot << ") on element of RemoveTaxCollectorOrderedSpellMessage.slot.";
  }
}

RemoveTaxCollectorOrderedSpellMessage::RemoveTaxCollectorOrderedSpellMessage()
{
  m_type = MessageEnum::REMOVETAXCOLLECTORORDEREDSPELLMESSAGE;
}

