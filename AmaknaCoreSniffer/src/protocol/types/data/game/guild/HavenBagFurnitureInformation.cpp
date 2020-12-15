#include "HavenBagFurnitureInformation.h"

void HavenBagFurnitureInformation::serialize(Writer *output)
{
  this->serializeAs_HavenBagFurnitureInformation(output);
}

void HavenBagFurnitureInformation::serializeAs_HavenBagFurnitureInformation(Writer *output)
{
  if(this->cellId < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
  output->writeInt((int)this->funitureId);
  if(this->orientation < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->orientation << ") on element orientation.";
  }
  output->writeByte(this->orientation);
}

void HavenBagFurnitureInformation::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagFurnitureInformation(input);
}

void HavenBagFurnitureInformation::deserializeAs_HavenBagFurnitureInformation(Reader *input)
{
  this->_cellIdFunc(input);
  this->_funitureIdFunc(input);
  this->_orientationFunc(input);
}

void HavenBagFurnitureInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagFurnitureInformation(tree);
}

void HavenBagFurnitureInformation::deserializeAsyncAs_HavenBagFurnitureInformation(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagFurnitureInformation::_cellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HavenBagFurnitureInformation::_funitureIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HavenBagFurnitureInformation::_orientationFunc, this, std::placeholders::_1));
}

void HavenBagFurnitureInformation::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->cellId << ") on element of HavenBagFurnitureInformation.cellId.";
  }
}

void HavenBagFurnitureInformation::_funitureIdFunc(Reader *input)
{
  this->funitureId = input->readInt();
}

void HavenBagFurnitureInformation::_orientationFunc(Reader *input)
{
  this->orientation = input->readByte();
  if(this->orientation < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->orientation << ") on element of HavenBagFurnitureInformation.orientation.";
  }
}

HavenBagFurnitureInformation::HavenBagFurnitureInformation()
{
  m_types<<ClassEnum::HAVENBAGFURNITUREINFORMATION;
}

bool HavenBagFurnitureInformation::operator==(const HavenBagFurnitureInformation &compared)
{
  if(cellId == compared.cellId)
  if(funitureId == compared.funitureId)
  if(orientation == compared.orientation)
  return true;
  
  return false;
}

