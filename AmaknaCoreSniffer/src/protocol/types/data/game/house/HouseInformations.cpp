#include "HouseInformations.h"

void HouseInformations::serialize(Writer *output)
{
  this->serializeAs_HouseInformations(output);
}

void HouseInformations::serializeAs_HouseInformations(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  output->writeVarShort((int)this->modelId);
}

void HouseInformations::deserialize(Reader *input)
{
  this->deserializeAs_HouseInformations(input);
}

void HouseInformations::deserializeAs_HouseInformations(Reader *input)
{
  this->_houseIdFunc(input);
  this->_modelIdFunc(input);
}

void HouseInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseInformations(tree);
}

void HouseInformations::deserializeAsyncAs_HouseInformations(FuncTree tree)
{
  tree.addChild(std::bind(&HouseInformations::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformations::_modelIdFunc, this, std::placeholders::_1));
}

void HouseInformations::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->houseId << ") on element of HouseInformations.houseId.";
  }
}

void HouseInformations::_modelIdFunc(Reader *input)
{
  this->modelId = input->readVarUhShort();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformations.modelId.";
  }
}

HouseInformations::HouseInformations()
{
  m_types<<ClassEnum::HOUSEINFORMATIONS;
}

bool HouseInformations::operator==(const HouseInformations &compared)
{
  if(houseId == compared.houseId)
  if(modelId == compared.modelId)
  return true;
  
  return false;
}

