#include "MoveTaxCollectorOrderedSpellMessage.h"

void MoveTaxCollectorOrderedSpellMessage::serialize(Writer *output)
{
  this->serializeAs_MoveTaxCollectorOrderedSpellMessage(output);
}

void MoveTaxCollectorOrderedSpellMessage::serializeAs_MoveTaxCollectorOrderedSpellMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  if(this->movedFrom < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->movedFrom << ") on element movedFrom.";
  }
  output->writeByte(this->movedFrom);
  if(this->movedTo < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->movedTo << ") on element movedTo.";
  }
  output->writeByte(this->movedTo);
}

void MoveTaxCollectorOrderedSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_MoveTaxCollectorOrderedSpellMessage(input);
}

void MoveTaxCollectorOrderedSpellMessage::deserializeAs_MoveTaxCollectorOrderedSpellMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
  this->_movedFromFunc(input);
  this->_movedToFunc(input);
}

void MoveTaxCollectorOrderedSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MoveTaxCollectorOrderedSpellMessage(tree);
}

void MoveTaxCollectorOrderedSpellMessage::deserializeAsyncAs_MoveTaxCollectorOrderedSpellMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MoveTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoveTaxCollectorOrderedSpellMessage::_movedFromFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoveTaxCollectorOrderedSpellMessage::_movedToFunc, this, std::placeholders::_1));
}

void MoveTaxCollectorOrderedSpellMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of MoveTaxCollectorOrderedSpellMessage.taxCollectorId.";
  }
}

void MoveTaxCollectorOrderedSpellMessage::_movedFromFunc(Reader *input)
{
  this->movedFrom = input->readByte();
  if(this->movedFrom < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->movedFrom << ") on element of MoveTaxCollectorOrderedSpellMessage.movedFrom.";
  }
}

void MoveTaxCollectorOrderedSpellMessage::_movedToFunc(Reader *input)
{
  this->movedTo = input->readByte();
  if(this->movedTo < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorOrderedSpellMessage -"<<"Forbidden value (" << this->movedTo << ") on element of MoveTaxCollectorOrderedSpellMessage.movedTo.";
  }
}

MoveTaxCollectorOrderedSpellMessage::MoveTaxCollectorOrderedSpellMessage()
{
  m_type = MessageEnum::MOVETAXCOLLECTORORDEREDSPELLMESSAGE;
}

