#include "SubscriptionLimitationMessage.h"

void SubscriptionLimitationMessage::serialize(Writer *output)
{
  this->serializeAs_SubscriptionLimitationMessage(output);
}

void SubscriptionLimitationMessage::serializeAs_SubscriptionLimitationMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void SubscriptionLimitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_SubscriptionLimitationMessage(input);
}

void SubscriptionLimitationMessage::deserializeAs_SubscriptionLimitationMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void SubscriptionLimitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SubscriptionLimitationMessage(tree);
}

void SubscriptionLimitationMessage::deserializeAsyncAs_SubscriptionLimitationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SubscriptionLimitationMessage::_reasonFunc, this, std::placeholders::_1));
}

void SubscriptionLimitationMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - SubscriptionLimitationMessage -"<<"Forbidden value (" << this->reason << ") on element of SubscriptionLimitationMessage.reason.";
  }
}

SubscriptionLimitationMessage::SubscriptionLimitationMessage()
{
  m_type = MessageEnum::SUBSCRIPTIONLIMITATIONMESSAGE;
}

