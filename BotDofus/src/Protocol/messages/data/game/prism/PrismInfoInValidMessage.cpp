#include "PrismInfoInValidMessage.h"

void PrismInfoInValidMessage::serialize(Writer *output)
{
  this->serializeAs_PrismInfoInValidMessage(output);
}

void PrismInfoInValidMessage::serializeAs_PrismInfoInValidMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void PrismInfoInValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismInfoInValidMessage(input);
}

void PrismInfoInValidMessage::deserializeAs_PrismInfoInValidMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void PrismInfoInValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismInfoInValidMessage(tree);
}

void PrismInfoInValidMessage::deserializeAsyncAs_PrismInfoInValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismInfoInValidMessage::_reasonFunc, this, std::placeholders::_1));
}

void PrismInfoInValidMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - PrismInfoInValidMessage -"<<"Forbidden value (" << this->reason << ") on element of PrismInfoInValidMessage.reason.";
  }
}

PrismInfoInValidMessage::PrismInfoInValidMessage()
{
  m_type = MessageEnum::PRISMINFOINVALIDMESSAGE;
}

