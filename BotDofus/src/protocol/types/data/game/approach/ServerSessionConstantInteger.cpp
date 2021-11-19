#include "ServerSessionConstantInteger.h"

void ServerSessionConstantInteger::serialize(Writer *output)
{
  this->serializeAs_ServerSessionConstantInteger(output);
}

void ServerSessionConstantInteger::serializeAs_ServerSessionConstantInteger(Writer *output)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(output);
  output->writeInt((int)this->value);
}

void ServerSessionConstantInteger::deserialize(Reader *input)
{
  this->deserializeAs_ServerSessionConstantInteger(input);
}

void ServerSessionConstantInteger::deserializeAs_ServerSessionConstantInteger(Reader *input)
{
  ServerSessionConstant::deserialize(input);
  this->_valueFunc(input);
}

void ServerSessionConstantInteger::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSessionConstantInteger(tree);
}

void ServerSessionConstantInteger::deserializeAsyncAs_ServerSessionConstantInteger(FuncTree tree)
{
  ServerSessionConstant::deserializeAsync(tree);
  tree.addChild(std::bind(&ServerSessionConstantInteger::_valueFunc, this, std::placeholders::_1));
}

void ServerSessionConstantInteger::_valueFunc(Reader *input)
{
  this->value = input->readInt();
}

ServerSessionConstantInteger::ServerSessionConstantInteger()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTINTEGER;
}

bool ServerSessionConstantInteger::operator==(const ServerSessionConstantInteger &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

