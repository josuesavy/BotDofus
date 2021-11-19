#include "IgnoredAddRequestMessage.h"

void IgnoredAddRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredAddRequestMessage(output);
}

void IgnoredAddRequestMessage::serializeAs_IgnoredAddRequestMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
  output->writeBool(this->session);
}

void IgnoredAddRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredAddRequestMessage(input);
}

void IgnoredAddRequestMessage::deserializeAs_IgnoredAddRequestMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
  this->_sessionFunc(input);
}

void IgnoredAddRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredAddRequestMessage(tree);
}

void IgnoredAddRequestMessage::deserializeAsyncAs_IgnoredAddRequestMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&IgnoredAddRequestMessage::_targettreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredAddRequestMessage::_sessionFunc, this, std::placeholders::_1));
}

void IgnoredAddRequestMessage::_targettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

void IgnoredAddRequestMessage::_sessionFunc(Reader *input)
{
  this->session = input->readBool();
}

IgnoredAddRequestMessage::IgnoredAddRequestMessage()
{
  m_type = MessageEnum::IGNOREDADDREQUESTMESSAGE;
  m_needsHash = true;
}

