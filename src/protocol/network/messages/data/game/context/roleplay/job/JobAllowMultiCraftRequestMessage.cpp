#include "JobAllowMultiCraftRequestMessage.h"

void JobAllowMultiCraftRequestMessage::serialize(Writer *output)
{
  this->serializeAs_JobAllowMultiCraftRequestMessage(output);
}

void JobAllowMultiCraftRequestMessage::serializeAs_JobAllowMultiCraftRequestMessage(Writer *output)
{
  output->writeBool(this->enabled);
}

void JobAllowMultiCraftRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobAllowMultiCraftRequestMessage(input);
}

void JobAllowMultiCraftRequestMessage::deserializeAs_JobAllowMultiCraftRequestMessage(Reader *input)
{
  this->_enabledFunc(input);
}

void JobAllowMultiCraftRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobAllowMultiCraftRequestMessage(tree);
}

void JobAllowMultiCraftRequestMessage::deserializeAsyncAs_JobAllowMultiCraftRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&JobAllowMultiCraftRequestMessage::_enabledFunc, this, std::placeholders::_1));
}

void JobAllowMultiCraftRequestMessage::_enabledFunc(Reader *input)
{
  this->enabled = input->readBool();
}

JobAllowMultiCraftRequestMessage::JobAllowMultiCraftRequestMessage()
{
  m_type = MessageEnum::JOBALLOWMULTICRAFTREQUESTMESSAGE;
}

