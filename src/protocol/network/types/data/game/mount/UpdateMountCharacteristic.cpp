#include "UpdateMountCharacteristic.h"

void UpdateMountCharacteristic::serialize(Writer *output)
{
  this->serializeAs_UpdateMountCharacteristic(output);
}

void UpdateMountCharacteristic::serializeAs_UpdateMountCharacteristic(Writer *output)
{
  output->writeByte(this->type);
}

void UpdateMountCharacteristic::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMountCharacteristic(input);
}

void UpdateMountCharacteristic::deserializeAs_UpdateMountCharacteristic(Reader *input)
{
  this->_typeFunc(input);
}

void UpdateMountCharacteristic::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMountCharacteristic(tree);
}

void UpdateMountCharacteristic::deserializeAsyncAs_UpdateMountCharacteristic(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateMountCharacteristic::_typeFunc, this, std::placeholders::_1));
}

void UpdateMountCharacteristic::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - UpdateMountCharacteristic -"<<"Forbidden value (" << this->type << ") on element of UpdateMountCharacteristic.type.";
  }
}

UpdateMountCharacteristic::UpdateMountCharacteristic()
{
  m_types<<ClassEnum::UPDATEMOUNTCHARACTERISTIC;
}

bool UpdateMountCharacteristic::operator==(const UpdateMountCharacteristic &compared)
{
  if(type == compared.type)
  return true;
  
  return false;
}

