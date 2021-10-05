#include "SetEnablePVPRequestMessage.h"

void SetEnablePVPRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SetEnablePVPRequestMessage(output);
}

void SetEnablePVPRequestMessage::serializeAs_SetEnablePVPRequestMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void SetEnablePVPRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SetEnablePVPRequestMessage(input);
}

void SetEnablePVPRequestMessage::deserializeAs_SetEnablePVPRequestMessage(Reader *input)
{
  this->_enableFunc(input);
}

void SetEnablePVPRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SetEnablePVPRequestMessage(tree);
}

void SetEnablePVPRequestMessage::deserializeAsyncAs_SetEnablePVPRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SetEnablePVPRequestMessage::_enableFunc, this, std::placeholders::_1));
}

void SetEnablePVPRequestMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

SetEnablePVPRequestMessage::SetEnablePVPRequestMessage()
{
  m_type = MessageEnum::SETENABLEPVPREQUESTMESSAGE;
}

