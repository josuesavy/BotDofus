#include "HaapiApiKeyMessage.h"

void HaapiApiKeyMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiApiKeyMessage(output);
}

void HaapiApiKeyMessage::serializeAs_HaapiApiKeyMessage(Writer *output)
{
  output->writeUTF(this->token);
}

void HaapiApiKeyMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiApiKeyMessage(input);
}

void HaapiApiKeyMessage::deserializeAs_HaapiApiKeyMessage(Reader *input)
{
  this->_tokenFunc(input);
}

void HaapiApiKeyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiApiKeyMessage(tree);
}

void HaapiApiKeyMessage::deserializeAsyncAs_HaapiApiKeyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiApiKeyMessage::_tokenFunc, this, std::placeholders::_1));
}

void HaapiApiKeyMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

HaapiApiKeyMessage::HaapiApiKeyMessage()
{
  m_type = MessageEnum::HAAPIAPIKEYMESSAGE;
}

