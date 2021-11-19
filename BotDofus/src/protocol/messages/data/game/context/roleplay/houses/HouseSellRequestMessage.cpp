#include "HouseSellRequestMessage.h"

void HouseSellRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseSellRequestMessage(output);
}

void HouseSellRequestMessage::serializeAs_HouseSellRequestMessage(Writer *output)
{
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
  output->writeBool(this->forSale);
}

void HouseSellRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseSellRequestMessage(input);
}

void HouseSellRequestMessage::deserializeAs_HouseSellRequestMessage(Reader *input)
{
  this->_instanceIdFunc(input);
  this->_amountFunc(input);
  this->_forSaleFunc(input);
}

void HouseSellRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseSellRequestMessage(tree);
}

void HouseSellRequestMessage::deserializeAsyncAs_HouseSellRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseSellRequestMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseSellRequestMessage::_amountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseSellRequestMessage::_forSaleFunc, this, std::placeholders::_1));
}

void HouseSellRequestMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseSellRequestMessage.instanceId.";
  }
}

void HouseSellRequestMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->amount << ") on element of HouseSellRequestMessage.amount.";
  }
}

void HouseSellRequestMessage::_forSaleFunc(Reader *input)
{
  this->forSale = input->readBool();
}

HouseSellRequestMessage::HouseSellRequestMessage()
{
  m_type = MessageEnum::HOUSESELLREQUESTMESSAGE;
}

