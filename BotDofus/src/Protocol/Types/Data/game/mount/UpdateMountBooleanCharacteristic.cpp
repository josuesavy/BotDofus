#include "UpdateMountBooleanCharacteristic.h"

void UpdateMountBooleanCharacteristic::serialize(Writer *output)
{
  this->serializeAs_UpdateMountBooleanCharacteristic(output);
}

void UpdateMountBooleanCharacteristic::serializeAs_UpdateMountBooleanCharacteristic(Writer *output)
{
  UpdateMountCharacteristic::serializeAs_UpdateMountCharacteristic(output);
  output->writeBool(this->value);
}

void UpdateMountBooleanCharacteristic::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMountBooleanCharacteristic(input);
}

void UpdateMountBooleanCharacteristic::deserializeAs_UpdateMountBooleanCharacteristic(Reader *input)
{
  UpdateMountCharacteristic::deserialize(input);
  this->_valueFunc(input);
}

void UpdateMountBooleanCharacteristic::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMountBooleanCharacteristic(tree);
}

void UpdateMountBooleanCharacteristic::deserializeAsyncAs_UpdateMountBooleanCharacteristic(FuncTree tree)
{
  UpdateMountCharacteristic::deserializeAsync(tree);
  tree.addChild(std::bind(&UpdateMountBooleanCharacteristic::_valueFunc, this, std::placeholders::_1));
}

void UpdateMountBooleanCharacteristic::_valueFunc(Reader *input)
{
  this->value = input->readBool();
}

UpdateMountBooleanCharacteristic::UpdateMountBooleanCharacteristic()
{
  m_types<<ClassEnum::UPDATEMOUNTBOOLEANCHARACTERISTIC;
}

bool UpdateMountBooleanCharacteristic::operator==(const UpdateMountBooleanCharacteristic &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

