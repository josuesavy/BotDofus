#include "BasicWhoIsNoMatchMessage.h"

void BasicWhoIsNoMatchMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoIsNoMatchMessage(output);
}

void BasicWhoIsNoMatchMessage::serializeAs_BasicWhoIsNoMatchMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void BasicWhoIsNoMatchMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoIsNoMatchMessage(input);
}

void BasicWhoIsNoMatchMessage::deserializeAs_BasicWhoIsNoMatchMessage(Reader *input)
{
  uint _id1 = uint(input->readUShort());
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
}

void BasicWhoIsNoMatchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoIsNoMatchMessage(tree);
}

void BasicWhoIsNoMatchMessage::deserializeAsyncAs_BasicWhoIsNoMatchMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&BasicWhoIsNoMatchMessage::_targettreeFunc, this, std::placeholders::_1));
}

void BasicWhoIsNoMatchMessage::_targettreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

BasicWhoIsNoMatchMessage::BasicWhoIsNoMatchMessage()
{
  m_type = MessageEnum::BASICWHOISNOMATCHMESSAGE;
}

