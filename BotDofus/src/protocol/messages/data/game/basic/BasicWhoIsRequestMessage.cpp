#include "BasicWhoIsRequestMessage.h"

void BasicWhoIsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoIsRequestMessage(output);
}

void BasicWhoIsRequestMessage::serializeAs_BasicWhoIsRequestMessage(Writer *output)
{
  output->writeBool(this->verbose);
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void BasicWhoIsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoIsRequestMessage(input);
}

void BasicWhoIsRequestMessage::deserializeAs_BasicWhoIsRequestMessage(Reader *input)
{
  this->_verboseFunc(input);
  uint _id2 = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id2));
  this->target->deserialize(input);
}

void BasicWhoIsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoIsRequestMessage(tree);
}

void BasicWhoIsRequestMessage::deserializeAsyncAs_BasicWhoIsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicWhoIsRequestMessage::_verboseFunc, this, std::placeholders::_1));
  this->_targettree = tree.addChild(std::bind(&BasicWhoIsRequestMessage::_targettreeFunc, this, std::placeholders::_1));
}

void BasicWhoIsRequestMessage::_verboseFunc(Reader *input)
{
  this->verbose = input->readBool();
}

void BasicWhoIsRequestMessage::_targettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

BasicWhoIsRequestMessage::BasicWhoIsRequestMessage()
{
  m_type = MessageEnum::BASICWHOISREQUESTMESSAGE;
  m_needsHash = true;
}

