#include "HaapiTokenMessage.h"

void HaapiTokenMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiTokenMessage(output);
}

void HaapiTokenMessage::serializeAs_HaapiTokenMessage(Writer *output)
{
  output->writeUTF(this->token);
}

void HaapiTokenMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiTokenMessage(input);
}

void HaapiTokenMessage::deserializeAs_HaapiTokenMessage(Reader *input)
{
  this->_tokenFunc(input);
}

void HaapiTokenMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiTokenMessage(tree);
}

void HaapiTokenMessage::deserializeAsyncAs_HaapiTokenMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiTokenMessage::_tokenFunc, this, std::placeholders::_1));
}

void HaapiTokenMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

HaapiTokenMessage::HaapiTokenMessage()
{
  m_type = MessageEnum::HAAPITOKENMESSAGE;
}

