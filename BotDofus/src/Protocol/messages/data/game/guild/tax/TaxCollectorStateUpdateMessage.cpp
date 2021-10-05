#include "TaxCollectorStateUpdateMessage.h"

void TaxCollectorStateUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorStateUpdateMessage(output);
}

void TaxCollectorStateUpdateMessage::serializeAs_TaxCollectorStateUpdateMessage(Writer *output)
{
  if(this->uniqueId < 0 || this->uniqueId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorStateUpdateMessage -"<<"Forbidden value (" << this->uniqueId << ") on element uniqueId.";
  }
  output->writeDouble(this->uniqueId);
  output->writeByte(this->state);
}

void TaxCollectorStateUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorStateUpdateMessage(input);
}

void TaxCollectorStateUpdateMessage::deserializeAs_TaxCollectorStateUpdateMessage(Reader *input)
{
  this->_uniqueIdFunc(input);
  this->_stateFunc(input);
}

void TaxCollectorStateUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorStateUpdateMessage(tree);
}

void TaxCollectorStateUpdateMessage::deserializeAsyncAs_TaxCollectorStateUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorStateUpdateMessage::_uniqueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStateUpdateMessage::_stateFunc, this, std::placeholders::_1));
}

void TaxCollectorStateUpdateMessage::_uniqueIdFunc(Reader *input)
{
  this->uniqueId = input->readDouble();
  if(this->uniqueId < 0 || this->uniqueId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorStateUpdateMessage -"<<"Forbidden value (" << this->uniqueId << ") on element of TaxCollectorStateUpdateMessage.uniqueId.";
  }
}

void TaxCollectorStateUpdateMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
}

TaxCollectorStateUpdateMessage::TaxCollectorStateUpdateMessage()
{
  m_type = MessageEnum::TAXCOLLECTORSTATEUPDATEMESSAGE;
}

