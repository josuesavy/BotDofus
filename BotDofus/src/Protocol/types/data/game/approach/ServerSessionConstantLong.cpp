#include "ServerSessionConstantLong.h"

void ServerSessionConstantLong::serialize(Writer *output)
{
  this->serializeAs_ServerSessionConstantLong(output);
}

void ServerSessionConstantLong::serializeAs_ServerSessionConstantLong(Writer *output)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(output);
  if(this->value < -9.007199254740992E15 || this->value > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ServerSessionConstantLong -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  output->writeDouble(this->value);
}

void ServerSessionConstantLong::deserialize(Reader *input)
{
  this->deserializeAs_ServerSessionConstantLong(input);
}

void ServerSessionConstantLong::deserializeAs_ServerSessionConstantLong(Reader *input)
{
  ServerSessionConstant::deserialize(input);
  this->_valueFunc(input);
}

void ServerSessionConstantLong::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSessionConstantLong(tree);
}

void ServerSessionConstantLong::deserializeAsyncAs_ServerSessionConstantLong(FuncTree tree)
{
  ServerSessionConstant::deserializeAsync(tree);
  tree.addChild(std::bind(&ServerSessionConstantLong::_valueFunc, this, std::placeholders::_1));
}

void ServerSessionConstantLong::_valueFunc(Reader *input)
{
  this->value = input->readDouble();
  if(this->value < -9.007199254740992E15 || this->value > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ServerSessionConstantLong -"<<"Forbidden value (" << this->value << ") on element of ServerSessionConstantLong.value.";
  }
}

ServerSessionConstantLong::ServerSessionConstantLong()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTLONG;
}

bool ServerSessionConstantLong::operator==(const ServerSessionConstantLong &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

