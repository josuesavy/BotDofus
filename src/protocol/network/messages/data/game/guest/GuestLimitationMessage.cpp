#include "GuestLimitationMessage.h"

void GuestLimitationMessage::serialize(Writer *output)
{
  this->serializeAs_GuestLimitationMessage(output);
}

void GuestLimitationMessage::serializeAs_GuestLimitationMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void GuestLimitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuestLimitationMessage(input);
}

void GuestLimitationMessage::deserializeAs_GuestLimitationMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void GuestLimitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuestLimitationMessage(tree);
}

void GuestLimitationMessage::deserializeAsyncAs_GuestLimitationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuestLimitationMessage::_reasonFunc, this, std::placeholders::_1));
}

void GuestLimitationMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - GuestLimitationMessage -"<<"Forbidden value (" << this->reason << ") on element of GuestLimitationMessage.reason.";
  }
}

GuestLimitationMessage::GuestLimitationMessage()
{
  m_type = MessageEnum::GUESTLIMITATIONMESSAGE;
}

