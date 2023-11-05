#include "ExchangeBidHouseBuyResultMessage.h"

void ExchangeBidHouseBuyResultMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseBuyResultMessage(output);
}

void ExchangeBidHouseBuyResultMessage::serializeAs_ExchangeBidHouseBuyResultMessage(Writer *output)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyResultMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeVarInt((int)this->uid);
  output->writeBool(this->bought);
}

void ExchangeBidHouseBuyResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseBuyResultMessage(input);
}

void ExchangeBidHouseBuyResultMessage::deserializeAs_ExchangeBidHouseBuyResultMessage(Reader *input)
{
  this->_uidFunc(input);
  this->_boughtFunc(input);
}

void ExchangeBidHouseBuyResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseBuyResultMessage(tree);
}

void ExchangeBidHouseBuyResultMessage::deserializeAsyncAs_ExchangeBidHouseBuyResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseBuyResultMessage::_uidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseBuyResultMessage::_boughtFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseBuyResultMessage::_uidFunc(Reader *input)
{
  this->uid = input->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyResultMessage -"<<"Forbidden value (" << this->uid << ") on element of ExchangeBidHouseBuyResultMessage.uid.";
  }
}

void ExchangeBidHouseBuyResultMessage::_boughtFunc(Reader *input)
{
  this->bought = input->readBool();
}

ExchangeBidHouseBuyResultMessage::ExchangeBidHouseBuyResultMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEBUYRESULTMESSAGE;
}

