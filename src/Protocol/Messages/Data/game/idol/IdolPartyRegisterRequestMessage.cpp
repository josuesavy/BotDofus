#include "IdolPartyRegisterRequestMessage.h"

void IdolPartyRegisterRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IdolPartyRegisterRequestMessage(output);
}

void IdolPartyRegisterRequestMessage::serializeAs_IdolPartyRegisterRequestMessage(Writer *output)
{
  output->writeBool(this->m_register);
}

void IdolPartyRegisterRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolPartyRegisterRequestMessage(input);
}

void IdolPartyRegisterRequestMessage::deserializeAs_IdolPartyRegisterRequestMessage(Reader *input)
{
  this->_registerFunc(input);
}

void IdolPartyRegisterRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolPartyRegisterRequestMessage(tree);
}

void IdolPartyRegisterRequestMessage::deserializeAsyncAs_IdolPartyRegisterRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolPartyRegisterRequestMessage::_registerFunc, this, std::placeholders::_1));
}

void IdolPartyRegisterRequestMessage::_registerFunc(Reader *input)
{
  this->m_register = input->readBool();
}

IdolPartyRegisterRequestMessage::IdolPartyRegisterRequestMessage()
{
  m_type = MessageEnum::IDOLPARTYREGISTERREQUESTMESSAGE;
}

