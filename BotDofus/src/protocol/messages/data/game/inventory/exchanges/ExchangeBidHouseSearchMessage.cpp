#include "ExchangeBidHouseSearchMessage.h"

void ExchangeBidHouseSearchMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseSearchMessage(output);
}

void ExchangeBidHouseSearchMessage::serializeAs_ExchangeBidHouseSearchMessage(Writer *output)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  output->writeBool(this->follow);
}

void ExchangeBidHouseSearchMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseSearchMessage(input);
}

void ExchangeBidHouseSearchMessage::deserializeAs_ExchangeBidHouseSearchMessage(Reader *input)
{
  this->_objectGIDFunc(input);
  this->_followFunc(input);
}

void ExchangeBidHouseSearchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseSearchMessage(tree);
}

void ExchangeBidHouseSearchMessage::deserializeAsyncAs_ExchangeBidHouseSearchMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseSearchMessage::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseSearchMessage::_followFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseSearchMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeBidHouseSearchMessage.objectGID.";
  }
}

void ExchangeBidHouseSearchMessage::_followFunc(Reader *input)
{
  this->follow = input->readBool();
}

ExchangeBidHouseSearchMessage::ExchangeBidHouseSearchMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSESEARCHMESSAGE;
}

