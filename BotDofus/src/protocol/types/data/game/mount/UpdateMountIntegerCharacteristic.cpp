#include "UpdateMountIntegerCharacteristic.h"

void UpdateMountIntegerCharacteristic::serialize(Writer *output)
{
  this->serializeAs_UpdateMountIntegerCharacteristic(output);
}

void UpdateMountIntegerCharacteristic::serializeAs_UpdateMountIntegerCharacteristic(Writer *output)
{
  UpdateMountCharacteristic::serializeAs_UpdateMountCharacteristic(output);
  output->writeInt((int)this->value);
}

void UpdateMountIntegerCharacteristic::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMountIntegerCharacteristic(input);
}

void UpdateMountIntegerCharacteristic::deserializeAs_UpdateMountIntegerCharacteristic(Reader *input)
{
  UpdateMountCharacteristic::deserialize(input);
  this->_valueFunc(input);
}

void UpdateMountIntegerCharacteristic::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMountIntegerCharacteristic(tree);
}

void UpdateMountIntegerCharacteristic::deserializeAsyncAs_UpdateMountIntegerCharacteristic(FuncTree tree)
{
  UpdateMountCharacteristic::deserializeAsync(tree);
  tree.addChild(std::bind(&UpdateMountIntegerCharacteristic::_valueFunc, this, std::placeholders::_1));
}

void UpdateMountIntegerCharacteristic::_valueFunc(Reader *input)
{
  this->value = input->readInt();
}

UpdateMountIntegerCharacteristic::UpdateMountIntegerCharacteristic()
{
  m_types<<ClassEnum::UPDATEMOUNTINTEGERCHARACTERISTIC;
}

bool UpdateMountIntegerCharacteristic::operator==(const UpdateMountIntegerCharacteristic &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

