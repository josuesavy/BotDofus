#include "PaddockBuyResultMessage.h"

void PaddockBuyResultMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockBuyResultMessage(output);
}

void PaddockBuyResultMessage::serializeAs_PaddockBuyResultMessage(Writer *output)
{
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->paddockId << ") on element paddockId.";
  }
  output->writeDouble(this->paddockId);
  output->writeBool(this->bought);
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
  }
  output->writeVarLong((double)this->realPrice);
}

void PaddockBuyResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockBuyResultMessage(input);
}

void PaddockBuyResultMessage::deserializeAs_PaddockBuyResultMessage(Reader *input)
{
  this->_paddockIdFunc(input);
  this->_boughtFunc(input);
  this->_realPriceFunc(input);
}

void PaddockBuyResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockBuyResultMessage(tree);
}

void PaddockBuyResultMessage::deserializeAsyncAs_PaddockBuyResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockBuyResultMessage::_paddockIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockBuyResultMessage::_boughtFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockBuyResultMessage::_realPriceFunc, this, std::placeholders::_1));
}

void PaddockBuyResultMessage::_paddockIdFunc(Reader *input)
{
  this->paddockId = input->readDouble();
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->paddockId << ") on element of PaddockBuyResultMessage.paddockId.";
  }
}

void PaddockBuyResultMessage::_boughtFunc(Reader *input)
{
  this->bought = input->readBool();
}

void PaddockBuyResultMessage::_realPriceFunc(Reader *input)
{
  this->realPrice = input->readVarUhLong();
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element of PaddockBuyResultMessage.realPrice.";
  }
}

PaddockBuyResultMessage::PaddockBuyResultMessage()
{
  m_type = MessageEnum::PADDOCKBUYRESULTMESSAGE;
}

