#include "IgnoredAddRequestMessage.h"

void IgnoredAddRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredAddRequestMessage(output);
}

void IgnoredAddRequestMessage::serializeAs_IgnoredAddRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
  output->writeBool(this->session);
}

void IgnoredAddRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredAddRequestMessage(input);
}

void IgnoredAddRequestMessage::deserializeAs_IgnoredAddRequestMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_sessionFunc(input);
}

void IgnoredAddRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredAddRequestMessage(tree);
}

void IgnoredAddRequestMessage::deserializeAsyncAs_IgnoredAddRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IgnoredAddRequestMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredAddRequestMessage::_sessionFunc, this, std::placeholders::_1));
}

void IgnoredAddRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
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

