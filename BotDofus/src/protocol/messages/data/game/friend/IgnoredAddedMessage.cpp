#include "IgnoredAddedMessage.h"

void IgnoredAddedMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredAddedMessage(output);
}

void IgnoredAddedMessage::serializeAs_IgnoredAddedMessage(Writer *output)
{
  output->writeShort((short)this->ignoreAdded->getTypes().last());
  this->ignoreAdded->serialize(output);
  output->writeBool(this->session);
}

void IgnoredAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredAddedMessage(input);
}

void IgnoredAddedMessage::deserializeAs_IgnoredAddedMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->ignoreAdded = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->ignoreAdded->deserialize(input);
  this->_sessionFunc(input);
}

void IgnoredAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredAddedMessage(tree);
}

void IgnoredAddedMessage::deserializeAsyncAs_IgnoredAddedMessage(FuncTree tree)
{
  this->_ignoreAddedtree = tree.addChild(std::bind(&IgnoredAddedMessage::_ignoreAddedtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredAddedMessage::_sessionFunc, this, std::placeholders::_1));
}

void IgnoredAddedMessage::_ignoreAddedtreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->ignoreAdded = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->ignoreAdded->deserializeAsync(this->_ignoreAddedtree);
}

void IgnoredAddedMessage::_sessionFunc(Reader *input)
{
  this->session = input->readBool();
}

IgnoredAddedMessage::IgnoredAddedMessage()
{
  m_type = MessageEnum::IGNOREDADDEDMESSAGE;
}

