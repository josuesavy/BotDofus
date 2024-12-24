#include "SubscriptionZoneMessage.h"

void SubscriptionZoneMessage::serialize(Writer *output)
{
  this->serializeAs_SubscriptionZoneMessage(output);
}

void SubscriptionZoneMessage::serializeAs_SubscriptionZoneMessage(Writer *output)
{
  output->writeBool(this->active);
}

void SubscriptionZoneMessage::deserialize(Reader *input)
{
  this->deserializeAs_SubscriptionZoneMessage(input);
}

void SubscriptionZoneMessage::deserializeAs_SubscriptionZoneMessage(Reader *input)
{
  this->_activeFunc(input);
}

void SubscriptionZoneMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SubscriptionZoneMessage(tree);
}

void SubscriptionZoneMessage::deserializeAsyncAs_SubscriptionZoneMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SubscriptionZoneMessage::_activeFunc, this, std::placeholders::_1));
}

void SubscriptionZoneMessage::_activeFunc(Reader *input)
{
  this->active = input->readBool();
}

SubscriptionZoneMessage::SubscriptionZoneMessage()
{
  m_type = MessageEnum::SUBSCRIPTIONZONEMESSAGE;
}

