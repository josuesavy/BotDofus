#include "ExchangeBidHouseListMessage.h"

void ExchangeBidHouseListMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseListMessage(output);
}

void ExchangeBidHouseListMessage::serializeAs_ExchangeBidHouseListMessage(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  output->writeBool(this->follow);
}

void ExchangeBidHouseListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseListMessage(input);
}

void ExchangeBidHouseListMessage::deserializeAs_ExchangeBidHouseListMessage(Reader *input)
{
  this->_idFunc(input);
  this->_followFunc(input);
}

void ExchangeBidHouseListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseListMessage(tree);
}

void ExchangeBidHouseListMessage::deserializeAsyncAs_ExchangeBidHouseListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseListMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseListMessage::_followFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseListMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeBidHouseListMessage.id.";
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

