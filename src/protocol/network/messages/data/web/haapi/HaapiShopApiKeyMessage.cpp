#include "HaapiShopApiKeyMessage.h"

void HaapiShopApiKeyMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiShopApiKeyMessage(output);
}

void HaapiShopApiKeyMessage::serializeAs_HaapiShopApiKeyMessage(Writer *output)
{
  output->writeUTF(this->token);
}

void HaapiShopApiKeyMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiShopApiKeyMessage(input);
}

void HaapiShopApiKeyMessage::deserializeAs_HaapiShopApiKeyMessage(Reader *input)
{
  this->_tokenFunc(input);
}

void HaapiShopApiKeyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiShopApiKeyMessage(tree);
}

void HaapiShopApiKeyMessage::deserializeAsyncAs_HaapiShopApiKeyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiShopApiKeyMessage::_tokenFunc, this, std::placeholders::_1));
}

void HaapiShopApiKeyMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

HaapiShopApiKeyMessage::HaapiShopApiKeyMessage()
{
  m_type = MessageEnum::HAAPISHOPAPIKEYMESSAGE;
}

