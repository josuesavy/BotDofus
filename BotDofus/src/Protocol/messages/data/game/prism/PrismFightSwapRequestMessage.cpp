#include "PrismFightSwapRequestMessage.h"

void PrismFightSwapRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightSwapRequestMessage(output);
}

void PrismFightSwapRequestMessage::serializeAs_PrismFightSwapRequestMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
}

void PrismFightSwapRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightSwapRequestMessage(input);
}

void PrismFightSwapRequestMessage::deserializeAs_PrismFightSwapRequestMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_targetIdFunc(input);
}

void PrismFightSwapRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightSwapRequestMessage(tree);
}

void PrismFightSwapRequestMessage::deserializeAsyncAs_PrismFightSwapRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightSwapRequestMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightSwapRequestMessage::_targetIdFunc, this, std::placeholders::_1));
}

void PrismFightSwapRequestMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightSwapRequestMessage.subAreaId.";
  }
}

void PrismFightSwapRequestMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of PrismFightSwapRequestMessage.targetId.";
  }
}

PrismFightSwapRequestMessage::PrismFightSwapRequestMessage()
{
  m_type = MessageEnum::PRISMFIGHTSWAPREQUESTMESSAGE;
}

