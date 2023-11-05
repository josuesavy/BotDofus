#include "HouseBuyRequestMessage.h"

void HouseBuyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseBuyRequestMessage(output);
}

void HouseBuyRequestMessage::serializeAs_HouseBuyRequestMessage(Writer *output)
{
  if(this->proposedPrice < 0 || this->proposedPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element proposedPrice.";
  }
  output->writeVarLong((double)this->proposedPrice);
}

void HouseBuyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseBuyRequestMessage(input);
}

void HouseBuyRequestMessage::deserializeAs_HouseBuyRequestMessage(Reader *input)
{
  this->_proposedPriceFunc(input);
}

void HouseBuyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseBuyRequestMessage(tree);
}

void HouseBuyRequestMessage::deserializeAsyncAs_HouseBuyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseBuyRequestMessage::_proposedPriceFunc, this, std::placeholders::_1));
}

void HouseBuyRequestMessage::_proposedPriceFunc(Reader *input)
{
  this->proposedPrice = input->readVarUhLong();
  if(this->proposedPrice < 0 || this->proposedPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element of HouseBuyRequestMessage.proposedPrice.";
  }
}

HouseBuyRequestMessage::HouseBuyRequestMessage()
{
  m_type = MessageEnum::HOUSEBUYREQUESTMESSAGE;
}

