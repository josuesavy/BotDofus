#include "AnomalyOpenedMessage.h"

void AnomalyOpenedMessage::serialize(Writer *output)
{
  this->serializeAs_AnomalyOpenedMessage(output);
}

void AnomalyOpenedMessage::serializeAs_AnomalyOpenedMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalyOpenedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void AnomalyOpenedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AnomalyOpenedMessage(input);
}

void AnomalyOpenedMessage::deserializeAs_AnomalyOpenedMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
}

void AnomalyOpenedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AnomalyOpenedMessage(tree);
}

void AnomalyOpenedMessage::deserializeAsyncAs_AnomalyOpenedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AnomalyOpenedMessage::_subAreaIdFunc, this, std::placeholders::_1));
}

void AnomalyOpenedMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalyOpenedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of AnomalyOpenedMessage.subAreaId.";
  }
}

AnomalyOpenedMessage::AnomalyOpenedMessage()
{
  m_type = MessageEnum::ANOMALYOPENEDMESSAGE;
}

