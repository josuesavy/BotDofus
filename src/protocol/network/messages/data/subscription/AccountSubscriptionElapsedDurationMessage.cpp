#include "AccountSubscriptionElapsedDurationMessage.h"

void AccountSubscriptionElapsedDurationMessage::serialize(Writer *output)
{
  this->serializeAs_AccountSubscriptionElapsedDurationMessage(output);
}

void AccountSubscriptionElapsedDurationMessage::serializeAs_AccountSubscriptionElapsedDurationMessage(Writer *output)
{
  if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountSubscriptionElapsedDurationMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element subscriptionElapsedDuration.";
  }
  output->writeDouble(this->subscriptionElapsedDuration);
}

void AccountSubscriptionElapsedDurationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccountSubscriptionElapsedDurationMessage(input);
}

void AccountSubscriptionElapsedDurationMessage::deserializeAs_AccountSubscriptionElapsedDurationMessage(Reader *input)
{
  this->_subscriptionElapsedDurationFunc(input);
}

void AccountSubscriptionElapsedDurationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountSubscriptionElapsedDurationMessage(tree);
}

void AccountSubscriptionElapsedDurationMessage::deserializeAsyncAs_AccountSubscriptionElapsedDurationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AccountSubscriptionElapsedDurationMessage::_subscriptionElapsedDurationFunc, this, std::placeholders::_1));
}

void AccountSubscriptionElapsedDurationMessage::_subscriptionElapsedDurationFunc(Reader *input)
{
  this->subscriptionElapsedDuration = input->readDouble();
  if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountSubscriptionElapsedDurationMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element of AccountSubscriptionElapsedDurationMessage.subscriptionElapsedDuration.";
  }
}

AccountSubscriptionElapsedDurationMessage::AccountSubscriptionElapsedDurationMessage()
{
  m_type = MessageEnum::ACCOUNTSUBSCRIPTIONELAPSEDDURATIONMESSAGE;
}

