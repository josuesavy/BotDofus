#include "uuid.h"

void uuid::serialize(Writer *output)
{
  this->serializeAs_uuid(output);
}

void uuid::serializeAs_uuid(Writer *output)
{
  output->writeUTF(this->uuidString);
}

void uuid::deserialize(Reader *input)
{
  this->deserializeAs_uuid(input);
}

void uuid::deserializeAs_uuid(Reader *input)
{
  this->_uuidStringFunc(input);
}

void uuid::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_uuid(tree);
}

void uuid::deserializeAsyncAs_uuid(FuncTree tree)
{
  tree.addChild(std::bind(&uuid::_uuidStringFunc, this, std::placeholders::_1));
}

void uuid::_uuidStringFunc(Reader *input)
{
  this->uuidString = input->readUTF();
}

uuid::uuid()
{
  m_types<<ClassEnum::UUID;
}

bool uuid::operator==(const uuid &compared)
{
  if(uuidString == compared.uuidString)
  return true;
  
  return false;
}

