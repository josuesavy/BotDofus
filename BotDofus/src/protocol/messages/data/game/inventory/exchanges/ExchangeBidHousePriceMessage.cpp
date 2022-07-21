#include "ExchangeBidHousePriceMessage.h"

void ExchangeBidHousePriceMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHousePriceMessage(output);
}

void ExchangeBidHousePriceMessage::serializeAs_ExchangeBidHousePriceMessage(Writer *output)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
}

void ExchangeBidHousePriceMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHousePriceMessage(input);
}

void ExchangeBidHousePriceMessage::deserializeAs_ExchangeBidHousePriceMessage(Reader *input)
{
  this->_objectGIDFunc(input);
}

void ExchangeBidHousePriceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHousePriceMessage(tree);
}

void ExchangeBidHousePriceMessage::deserializeAsyncAs_ExchangeBidHousePriceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHousePriceMessage::_objectGIDFunc, this, std::placeholders::_1));
}

void ExchangeBidHousePriceMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeBidHousePriceMessage.objectGID.";
  }
}

ExchangeBidHousePriceMessage::ExchangeBidHousePriceMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEPRICEMESSAGE;
}

