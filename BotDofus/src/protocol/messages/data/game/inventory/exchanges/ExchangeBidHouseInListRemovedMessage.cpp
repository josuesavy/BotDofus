#include "ExchangeBidHouseInListRemovedMessage.h"

void ExchangeBidHouseInListRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseInListRemovedMessage(output);
}

void ExchangeBidHouseInListRemovedMessage::serializeAs_ExchangeBidHouseInListRemovedMessage(Writer *output)
{
  output->writeInt((int)this->itemUID);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListRemovedMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListRemovedMessage -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
  }
  output->writeInt((int)this->objectType);
}

void ExchangeBidHouseInListRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseInListRemovedMessage(input);
}

void ExchangeBidHouseInListRemovedMessage::deserializeAs_ExchangeBidHouseInListRemovedMessage(Reader *input)
{
  this->_itemUIDFunc(input);
  this->_objectGIDFunc(input);
  this->_objectTypeFunc(input);
}

void ExchangeBidHouseInListRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseInListRemovedMessage(tree);
}

void ExchangeBidHouseInListRemovedMessage::deserializeAsyncAs_ExchangeBidHouseInListRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseInListRemovedMessage::_itemUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseInListRemovedMessage::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseInListRemovedMessage::_objectTypeFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseInListRemovedMessage::_itemUIDFunc(Reader *input)
{
  this->itemUID = input->readInt();
}

void ExchangeBidHouseInListRemovedMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListRemovedMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeBidHouseInListRemovedMessage.objectGID.";
  }
}

void ExchangeBidHouseInListRemovedMessage::_objectTypeFunc(Reader *input)
{
  this->objectType = input->readInt();
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListRemovedMessage -"<<"Forbidden value (" << this->objectType << ") on element of ExchangeBidHouseInListRemovedMessage.objectType.";
  }
}

ExchangeBidHouseInListRemovedMessage::ExchangeBidHouseInListRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE;
}

