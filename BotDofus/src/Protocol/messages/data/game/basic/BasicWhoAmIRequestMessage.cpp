#include "BasicWhoAmIRequestMessage.h"

void BasicWhoAmIRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoAmIRequestMessage(output);
}

void BasicWhoAmIRequestMessage::serializeAs_BasicWhoAmIRequestMessage(Writer *output)
{
  output->writeBool(this->verbose);
}

void BasicWhoAmIRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoAmIRequestMessage(input);
}

void BasicWhoAmIRequestMessage::deserializeAs_BasicWhoAmIRequestMessage(Reader *input)
{
  this->_verboseFunc(input);
}

void BasicWhoAmIRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoAmIRequestMessage(tree);
}

void BasicWhoAmIRequestMessage::deserializeAsyncAs_BasicWhoAmIRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicWhoAmIRequestMessage::_verboseFunc, this, std::placeholders::_1));
}

void BasicWhoAmIRequestMessage::_verboseFunc(Reader *input)
{
  this->verbose = input->readBool();
}

BasicWhoAmIRequestMessage::BasicWhoAmIRequestMessage()
{
  m_type = MessageEnum::BASICWHOAMIREQUESTMESSAGE;
}

