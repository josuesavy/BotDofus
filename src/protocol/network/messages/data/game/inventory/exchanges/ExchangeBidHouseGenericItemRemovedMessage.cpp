#include "ExchangeBidHouseGenericItemRemovedMessage.h"

void ExchangeBidHouseGenericItemRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseGenericItemRemovedMessage(output);
}

void ExchangeBidHouseGenericItemRemovedMessage::serializeAs_ExchangeBidHouseGenericItemRemovedMessage(Writer *output)
{
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemRemovedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element objGenericId.";
  }
  output->writeVarInt((int)this->objGenericId);
}

void ExchangeBidHouseGenericItemRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(input);
}

void ExchangeBidHouseGenericItemRemovedMessage::deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(Reader *input)
{
  this->_objGenericIdFunc(input);
}

void ExchangeBidHouseGenericItemRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseGenericItemRemovedMessage(tree);
}

void ExchangeBidHouseGenericItemRemovedMessage::deserializeAsyncAs_ExchangeBidHouseGenericItemRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseGenericItemRemovedMessage::_objGenericIdFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseGenericItemRemovedMessage::_objGenericIdFunc(Reader *input)
{
  this->objGenericId = input->readVarUhInt();
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemRemovedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element of ExchangeBidHouseGenericItemRemovedMessage.objGenericId.";
  }
}

ExchangeBidHouseGenericItemRemovedMessage::ExchangeBidHouseGenericItemRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE;
}

