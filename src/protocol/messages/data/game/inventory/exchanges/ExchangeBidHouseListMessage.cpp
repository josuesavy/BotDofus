#include "ExchangeBidHouseListMessage.h"

void ExchangeBidHouseListMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseListMessage(output);
}

void ExchangeBidHouseListMessage::serializeAs_ExchangeBidHouseListMessage(Writer *output)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  output->writeBool(this->follow);
}

void ExchangeBidHouseListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseListMessage(input);
}

void ExchangeBidHouseListMessage::deserializeAs_ExchangeBidHouseListMessage(Reader *input)
{
  this->_objectGIDFunc(input);
  this->_followFunc(input);
}

void ExchangeBidHouseListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseListMessage(tree);
}

void ExchangeBidHouseListMessage::deserializeAsyncAs_ExchangeBidHouseListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseListMessage::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseListMessage::_followFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseListMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeBidHouseListMessage.objectGID.";
  }
}

void ExchangeBidHouseListMessage::_followFunc(Reader *input)
{
  this->follow = input->readBool();
}

ExchangeBidHouseListMessage::ExchangeBidHouseListMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSELISTMESSAGE;
}

