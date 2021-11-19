#include "ProtocolRequired.h"

void ProtocolRequired::serialize(Writer *output)
{
  this->serializeAs_ProtocolRequired(output);
}

void ProtocolRequired::serializeAs_ProtocolRequired(Writer *output)
{
  output->writeUTF(this->version);
}

void ProtocolRequired::deserialize(Reader *input)
{
  this->deserializeAs_ProtocolRequired(input);
}

void ProtocolRequired::deserializeAs_ProtocolRequired(Reader *input)
{
  this->_versionFunc(input);
}

void ProtocolRequired::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ProtocolRequired(tree);
}

void ProtocolRequired::deserializeAsyncAs_ProtocolRequired(FuncTree tree)
{
  tree.addChild(std::bind(&ProtocolRequired::_versionFunc, this, std::placeholders::_1));
}

void ProtocolRequired::_versionFunc(Reader *input)
{
  this->version = input->readUTF();
}

ProtocolRequired::ProtocolRequired()
{
  m_type = MessageEnum::PROTOCOLREQUIRED;
}

