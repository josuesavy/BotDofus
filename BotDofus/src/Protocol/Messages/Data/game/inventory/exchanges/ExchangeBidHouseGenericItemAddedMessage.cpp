#include "ExchangeBidHouseGenericItemAddedMessage.h"

void ExchangeBidHouseGenericItemAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseGenericItemAddedMessage(output);
}

void ExchangeBidHouseGenericItemAddedMessage::serializeAs_ExchangeBidHouseGenericItemAddedMessage(Writer *output)
{
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemAddedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element objGenericId.";
  }
  output->writeVarShort((int)this->objGenericId);
}

void ExchangeBidHouseGenericItemAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseGenericItemAddedMessage(input);
}

void ExchangeBidHouseGenericItemAddedMessage::deserializeAs_ExchangeBidHouseGenericItemAddedMessage(Reader *input)
{
  this->_objGenericIdFunc(input);
}

void ExchangeBidHouseGenericItemAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseGenericItemAddedMessage(tree);
}

void ExchangeBidHouseGenericItemAddedMessage::deserializeAsyncAs_ExchangeBidHouseGenericItemAddedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseGenericItemAddedMessage::_objGenericIdFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseGenericItemAddedMessage::_objGenericIdFunc(Reader *input)
{
  this->objGenericId = input->readVarUhShort();
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemAddedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element of ExchangeBidHouseGenericItemAddedMessage.objGenericId.";
  }
}

ExchangeBidHouseGenericItemAddedMessage::ExchangeBidHouseGenericItemAddedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE;
}

