#include "PrismSetSabotagedRequestMessage.h"

void PrismSetSabotagedRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismSetSabotagedRequestMessage(output);
}

void PrismSetSabotagedRequestMessage::serializeAs_PrismSetSabotagedRequestMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void PrismSetSabotagedRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismSetSabotagedRequestMessage(input);
}

void PrismSetSabotagedRequestMessage::deserializeAs_PrismSetSabotagedRequestMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
}

void PrismSetSabotagedRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismSetSabotagedRequestMessage(tree);
}

void PrismSetSabotagedRequestMessage::deserializeAsyncAs_PrismSetSabotagedRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismSetSabotagedRequestMessage::_subAreaIdFunc, this, std::placeholders::_1));
}

void PrismSetSabotagedRequestMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSetSabotagedRequestMessage.subAreaId.";
  }
}

PrismSetSabotagedRequestMessage::PrismSetSabotagedRequestMessage()
{
  m_type = MessageEnum::PRISMSETSABOTAGEDREQUESTMESSAGE;
}

