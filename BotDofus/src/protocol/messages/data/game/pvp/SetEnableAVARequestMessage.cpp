#include "SetEnableAVARequestMessage.h"

void SetEnableAVARequestMessage::serialize(Writer *output)
{
  this->serializeAs_SetEnableAVARequestMessage(output);
}

void SetEnableAVARequestMessage::serializeAs_SetEnableAVARequestMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void SetEnableAVARequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SetEnableAVARequestMessage(input);
}

void SetEnableAVARequestMessage::deserializeAs_SetEnableAVARequestMessage(Reader *input)
{
  this->_enableFunc(input);
}

void SetEnableAVARequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SetEnableAVARequestMessage(tree);
}

void SetEnableAVARequestMessage::deserializeAsyncAs_SetEnableAVARequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SetEnableAVARequestMessage::_enableFunc, this, std::placeholders::_1));
}

void SetEnableAVARequestMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

SetEnableAVARequestMessage::SetEnableAVARequestMessage()
{
  m_type = MessageEnum::SETENABLEAVAREQUESTMESSAGE;
}

