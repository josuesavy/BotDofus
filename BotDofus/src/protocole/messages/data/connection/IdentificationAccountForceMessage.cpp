#include "IdentificationAccountForceMessage.h"

void IdentificationAccountForceMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationAccountForceMessage(output);
}

void IdentificationAccountForceMessage::serializeAs_IdentificationAccountForceMessage(Writer *output)
{
  IdentificationMessage::serializeAs_IdentificationMessage(output);
  output->writeUTF(this->forcedAccountLogin);
}

void IdentificationAccountForceMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationAccountForceMessage(input);
}

void IdentificationAccountForceMessage::deserializeAs_IdentificationAccountForceMessage(Reader *input)
{
  IdentificationMessage::deserialize(input);
  this->_forcedAccountLoginFunc(input);
}

void IdentificationAccountForceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationAccountForceMessage(tree);
}

void IdentificationAccountForceMessage::deserializeAsyncAs_IdentificationAccountForceMessage(FuncTree tree)
{
  IdentificationMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&IdentificationAccountForceMessage::_forcedAccountLoginFunc, this, std::placeholders::_1));
}

void IdentificationAccountForceMessage::_forcedAccountLoginFunc(Reader *input)
{
  this->forcedAccountLogin = input->readUTF();
}

IdentificationAccountForceMessage::IdentificationAccountForceMessage()
{
  m_type = MessageEnum::IDENTIFICATIONACCOUNTFORCEMESSAGE;
}

