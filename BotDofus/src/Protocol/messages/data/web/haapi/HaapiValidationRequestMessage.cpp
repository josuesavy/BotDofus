#include "HaapiValidationRequestMessage.h"

void HaapiValidationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiValidationRequestMessage(output);
}

void HaapiValidationRequestMessage::serializeAs_HaapiValidationRequestMessage(Writer *output)
{
  output->writeUTF(this->transaction);
}

void HaapiValidationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiValidationRequestMessage(input);
}

void HaapiValidationRequestMessage::deserializeAs_HaapiValidationRequestMessage(Reader *input)
{
  this->_transactionFunc(input);
}

void HaapiValidationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiValidationRequestMessage(tree);
}

void HaapiValidationRequestMessage::deserializeAsyncAs_HaapiValidationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiValidationRequestMessage::_transactionFunc, this, std::placeholders::_1));
}

void HaapiValidationRequestMessage::_transactionFunc(Reader *input)
{
  this->transaction = input->readUTF();
}

HaapiValidationRequestMessage::HaapiValidationRequestMessage()
{
  m_type = MessageEnum::HAAPIVALIDATIONREQUESTMESSAGE;
}

