#include "BasicWhoIsRequestMessage.h"

void BasicWhoIsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoIsRequestMessage(output);
}

void BasicWhoIsRequestMessage::serializeAs_BasicWhoIsRequestMessage(Writer *output)
{
  output->writeBool(this->verbose);
  output->writeUTF(this->search);
}

void BasicWhoIsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoIsRequestMessage(input);
}

void BasicWhoIsRequestMessage::deserializeAs_BasicWhoIsRequestMessage(Reader *input)
{
  this->_verboseFunc(input);
  this->_searchFunc(input);
}

void BasicWhoIsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoIsRequestMessage(tree);
}

void BasicWhoIsRequestMessage::deserializeAsyncAs_BasicWhoIsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicWhoIsRequestMessage::_verboseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsRequestMessage::_searchFunc, this, std::placeholders::_1));
}

void BasicWhoIsRequestMessage::_verboseFunc(Reader *input)
{
  this->verbose = input->readBool();
}

void BasicWhoIsRequestMessage::_searchFunc(Reader *input)
{
  this->search = input->readUTF();
}

BasicWhoIsRequestMessage::BasicWhoIsRequestMessage()
{
  m_type = MessageEnum::BASICWHOISREQUESTMESSAGE;
  m_needsHash = true;
}

