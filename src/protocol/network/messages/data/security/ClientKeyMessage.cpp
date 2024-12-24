#include "ClientKeyMessage.h"

void ClientKeyMessage::serialize(Writer *output)
{
  this->serializeAs_ClientKeyMessage(output);
}

void ClientKeyMessage::serializeAs_ClientKeyMessage(Writer *output)
{
  output->writeUTF(this->key);
}

void ClientKeyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ClientKeyMessage(input);
}

void ClientKeyMessage::deserializeAs_ClientKeyMessage(Reader *input)
{
  this->_keyFunc(input);
}

void ClientKeyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ClientKeyMessage(tree);
}

void ClientKeyMessage::deserializeAsyncAs_ClientKeyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ClientKeyMessage::_keyFunc, this, std::placeholders::_1));
}

void ClientKeyMessage::_keyFunc(Reader *input)
{
  this->key = input->readUTF();
}

ClientKeyMessage::ClientKeyMessage()
{
  m_type = MessageEnum::CLIENTKEYMESSAGE;
  m_needsHash = true;
}

