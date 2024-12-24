#include "Uuid.h"

void Uuid::serialize(Writer *output)
{
  this->serializeAs_Uuid(output);
}

void Uuid::serializeAs_Uuid(Writer *output)
{
  output->writeUTF(this->uuidString);
}

void Uuid::deserialize(Reader *input)
{
  this->deserializeAs_Uuid(input);
}

void Uuid::deserializeAs_Uuid(Reader *input)
{
  this->_uuidStringFunc(input);
}

void Uuid::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Uuid(tree);
}

void Uuid::deserializeAsyncAs_Uuid(FuncTree tree)
{
  tree.addChild(std::bind(&Uuid::_uuidStringFunc, this, std::placeholders::_1));
}

void Uuid::_uuidStringFunc(Reader *input)
{
  this->uuidString = input->readUTF();
}

Uuid::Uuid()
{
  m_types<<ClassEnum::UUID;
}

bool Uuid::operator==(const Uuid &compared)
{
  if(uuidString == compared.uuidString)
  return true;
  
  return false;
}

