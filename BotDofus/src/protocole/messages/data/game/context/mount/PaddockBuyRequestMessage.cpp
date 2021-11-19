#include "PaddockBuyRequestMessage.h"

void PaddockBuyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockBuyRequestMessage(output);
}

void PaddockBuyRequestMessage::serializeAs_PaddockBuyRequestMessage(Writer *output)
{
  if(this->proposedPrice < 0 || this->proposedPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element proposedPrice.";
  }
  output->writeVarLong((double)this->proposedPrice);
}

void PaddockBuyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockBuyRequestMessage(input);
}

void PaddockBuyRequestMessage::deserializeAs_PaddockBuyRequestMessage(Reader *input)
{
  this->_proposedPriceFunc(input);
}

void PaddockBuyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockBuyRequestMessage(tree);
}

void PaddockBuyRequestMessage::deserializeAsyncAs_PaddockBuyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockBuyRequestMessage::_proposedPriceFunc, this, std::placeholders::_1));
}

void PaddockBuyRequestMessage::_proposedPriceFunc(Reader *input)
{
  this->proposedPrice = input->readVarUhLong();
  if(this->proposedPrice < 0 || this->proposedPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element of PaddockBuyRequestMessage.proposedPrice.";
  }
}

PaddockBuyRequestMessage::PaddockBuyRequestMessage()
{
  m_type = MessageEnum::PADDOCKBUYREQUESTMESSAGE;
}

