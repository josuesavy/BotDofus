#include "ExchangeBidHouseTypeMessage.h"

void ExchangeBidHouseTypeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseTypeMessage(output);
}

void ExchangeBidHouseTypeMessage::serializeAs_ExchangeBidHouseTypeMessage(Writer *output)
{
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseTypeMessage -"<<"Forbidden value (" << this->type << ") on element type.";
  }
  output->writeVarInt((int)this->type);
  output->writeBool(this->follow);
}

void ExchangeBidHouseTypeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseTypeMessage(input);
}

void ExchangeBidHouseTypeMessage::deserializeAs_ExchangeBidHouseTypeMessage(Reader *input)
{
  this->_typeFunc(input);
  this->_followFunc(input);
}

void ExchangeBidHouseTypeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseTypeMessage(tree);
}

void ExchangeBidHouseTypeMessage::deserializeAsyncAs_ExchangeBidHouseTypeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseTypeMessage::_typeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseTypeMessage::_followFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseTypeMessage::_typeFunc(Reader *input)
{
  this->type = input->readVarUhInt();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseTypeMessage -"<<"Forbidden value (" << this->type << ") on element of ExchangeBidHouseTypeMessage.type.";
  }
}

void ExchangeBidHouseTypeMessage::_followFunc(Reader *input)
{
  this->follow = input->readBool();
}

ExchangeBidHouseTypeMessage::ExchangeBidHouseTypeMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSETYPEMESSAGE;
}

