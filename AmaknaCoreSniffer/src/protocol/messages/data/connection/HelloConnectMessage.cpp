#include "HelloConnectMessage.h"

void HelloConnectMessage::serialize(Writer *output)
{
  this->serializeAs_HelloConnectMessage(output);
}

void HelloConnectMessage::serializeAs_HelloConnectMessage(Writer *output)
{
  output->writeUTF(this->salt);
  output->writeVarInt((int)this->key.size());
  for(uint _i2 = 0; _i2 < this->key.size(); _i2++)
  {
    output->writeByte(this->key[_i2]);
  }
}

void HelloConnectMessage::deserialize(Reader *input)
{
  this->deserializeAs_HelloConnectMessage(input);
}

void HelloConnectMessage::deserializeAs_HelloConnectMessage(Reader *input)
{
  auto _val2 = 0;
  this->_saltFunc(input);
  uint _keyLen = input->readVarInt();
  for(uint _i2 = 0; _i2 < _keyLen; _i2++)
  {
    _val2 = input->readByte();
    this->key.append(_val2);
  }
}

void HelloConnectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HelloConnectMessage(tree);
}

void HelloConnectMessage::deserializeAsyncAs_HelloConnectMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HelloConnectMessage::_saltFunc, this, std::placeholders::_1));
  this->_keytree = tree.addChild(std::bind(&HelloConnectMessage::_keytreeFunc, this, std::placeholders::_1));
}

void HelloConnectMessage::_saltFunc(Reader *input)
{
  this->salt = input->readUTF();
}

void HelloConnectMessage::_keytreeFunc(Reader *input)
{
  uint length = input->readVarInt();
  for(uint i = 0; i < length; i++)
  {
    this->_keytree.addChild(std::bind(&HelloConnectMessage::_keyFunc, this, std::placeholders::_1));
  }
}

void HelloConnectMessage::_keyFunc(Reader *input)
{
  int _val = input->readByte();
  this->key.append(_val);
}

HelloConnectMessage::HelloConnectMessage()
{
  m_type = MessageEnum::HELLOCONNECTMESSAGE;
}

