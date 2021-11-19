#include "ServerSessionConstantString.h"

void ServerSessionConstantString::serialize(Writer *output)
{
  this->serializeAs_ServerSessionConstantString(output);
}

void ServerSessionConstantString::serializeAs_ServerSessionConstantString(Writer *output)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(output);
  output->writeUTF(this->value);
}

void ServerSessionConstantString::deserialize(Reader *input)
{
  this->deserializeAs_ServerSessionConstantString(input);
}

void ServerSessionConstantString::deserializeAs_ServerSessionConstantString(Reader *input)
{
  ServerSessionConstant::deserialize(input);
  this->_valueFunc(input);
}

void ServerSessionConstantString::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSessionConstantString(tree);
}

void ServerSessionConstantString::deserializeAsyncAs_ServerSessionConstantString(FuncTree tree)
{
  ServerSessionConstant::deserializeAsync(tree);
  tree.addChild(std::bind(&ServerSessionConstantString::_valueFunc, this, std::placeholders::_1));
}

void ServerSessionConstantString::_valueFunc(Reader *input)
{
  this->value = input->readUTF();
}

ServerSessionConstantString::ServerSessionConstantString()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTSTRING;
}

bool ServerSessionConstantString::operator==(const ServerSessionConstantString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

