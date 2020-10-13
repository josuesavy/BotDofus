#include "AnomalyStateMessage.h"

void AnomalyStateMessage::serialize(Writer *output)
{
  this->serializeAs_AnomalyStateMessage(output);
}

void AnomalyStateMessage::serializeAs_AnomalyStateMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalyStateMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeBool(this->open);
  if(this->closingTime < 0 || this->closingTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AnomalyStateMessage -"<<"Forbidden value (" << this->closingTime << ") on element closingTime.";
  }
  output->writeVarLong((double)this->closingTime);
}

void AnomalyStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AnomalyStateMessage(input);
}

void AnomalyStateMessage::deserializeAs_AnomalyStateMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_openFunc(input);
  this->_closingTimeFunc(input);
}

void AnomalyStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AnomalyStateMessage(tree);
}

void AnomalyStateMessage::deserializeAsyncAs_AnomalyStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AnomalyStateMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AnomalyStateMessage::_openFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AnomalyStateMessage::_closingTimeFunc, this, std::placeholders::_1));
}

void AnomalyStateMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalyStateMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of AnomalyStateMessage.subAreaId.";
  }
}

void AnomalyStateMessage::_openFunc(Reader *input)
{
  this->open = input->readBool();
}

void AnomalyStateMessage::_closingTimeFunc(Reader *input)
{
  this->closingTime = input->readVarUhLong();
  if(this->closingTime < 0 || this->closingTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AnomalyStateMessage -"<<"Forbidden value (" << this->closingTime << ") on element of AnomalyStateMessage.closingTime.";
  }
}

AnomalyStateMessage::AnomalyStateMessage()
{
  m_type = MessageEnum::ANOMALYSTATEMESSAGE;
}

