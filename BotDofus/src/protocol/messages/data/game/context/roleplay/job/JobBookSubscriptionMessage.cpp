#include "JobBookSubscriptionMessage.h"

void JobBookSubscriptionMessage::serialize(Writer *output)
{
  this->serializeAs_JobBookSubscriptionMessage(output);
}

void JobBookSubscriptionMessage::serializeAs_JobBookSubscriptionMessage(Writer *output)
{
  output->writeShort((short)this->subscriptions.size());
  for(uint _i1 = 0; _i1 < this->subscriptions.size(); _i1++)
  {
    (this->subscriptions[_i1]).serializeAs_JobBookSubscription(output);
  }
}

void JobBookSubscriptionMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobBookSubscriptionMessage(input);
}

void JobBookSubscriptionMessage::deserializeAs_JobBookSubscriptionMessage(Reader *input)
{
  JobBookSubscription _item1 ;
  uint _subscriptionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _subscriptionsLen; _i1++)
  {
    _item1 = JobBookSubscription();
    _item1.deserialize(input);
    this->subscriptions.append(_item1);
  }
}

void JobBookSubscriptionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobBookSubscriptionMessage(tree);
}

void JobBookSubscriptionMessage::deserializeAsyncAs_JobBookSubscriptionMessage(FuncTree tree)
{
  this->_subscriptionstree = tree.addChild(std::bind(&JobBookSubscriptionMessage::_subscriptionstreeFunc, this, std::placeholders::_1));
}

void JobBookSubscriptionMessage::_subscriptionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_subscriptionstree.addChild(std::bind(&JobBookSubscriptionMessage::_subscriptionsFunc, this, std::placeholders::_1));
  }
}

void JobBookSubscriptionMessage::_subscriptionsFunc(Reader *input)
{
  JobBookSubscription _item = JobBookSubscription();
  _item.deserialize(input);
  this->subscriptions.append(_item);
}

JobBookSubscriptionMessage::JobBookSubscriptionMessage()
{
  m_type = MessageEnum::JOBBOOKSUBSCRIPTIONMESSAGE;
}

