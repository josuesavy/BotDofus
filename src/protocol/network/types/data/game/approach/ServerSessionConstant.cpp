#include "ServerSessionConstant.h"

void ServerSessionConstant::serialize(Writer *output)
{
  this->serializeAs_ServerSessionConstant(output);
}

void ServerSessionConstant::serializeAs_ServerSessionConstant(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ServerSessionConstant -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
}

void ServerSessionConstant::deserialize(Reader *input)
{
  this->deserializeAs_ServerSessionConstant(input);
}

void ServerSessionConstant::deserializeAs_ServerSessionConstant(Reader *input)
{
  this->_idFunc(input);
}

void ServerSessionConstant::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSessionConstant(tree);
}

void ServerSessionConstant::deserializeAsyncAs_ServerSessionConstant(FuncTree tree)
{
  tree.addChild(std::bind(&ServerSessionConstant::_idFunc, this, std::placeholders::_1));
}

void ServerSessionConstant::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ServerSessionConstant -"<<"Forbidden value (" << this->id << ") on element of ServerSessionConstant.id.";
  }
}

ServerSessionConstant::ServerSessionConstant()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANT;
}

bool ServerSessionConstant::operator==(const ServerSessionConstant &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

