#include "ExchangeBidHouseSearchMessage.h"

void ExchangeBidHouseSearchMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseSearchMessage(output);
}

void ExchangeBidHouseSearchMessage::serializeAs_ExchangeBidHouseSearchMessage(Writer *output)
{
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->genId << ") on element genId.";
  }
  output->writeVarShort((int)this->genId);
  output->writeBool(this->follow);
}

void ExchangeBidHouseSearchMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseSearchMessage(input);
}

void ExchangeBidHouseSearchMessage::deserializeAs_ExchangeBidHouseSearchMessage(Reader *input)
{
  this->_genIdFunc(input);
  this->_followFunc(input);
}

void ExchangeBidHouseSearchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseSearchMessage(tree);
}

void ExchangeBidHouseSearchMessage::deserializeAsyncAs_ExchangeBidHouseSearchMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseSearchMessage::_genIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseSearchMessage::_followFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseSearchMessage::_genIdFunc(Reader *input)
{
  this->genId = input->readVarUhShort();
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->genId << ") on element of ExchangeBidHouseSearchMessage.genId.";
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

