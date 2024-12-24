#include "PrismInformation.h"

void PrismInformation::serialize(Writer *output)
{
  this->serializeAs_PrismInformation(output);
}

void PrismInformation::serializeAs_PrismInformation(Writer *output)
{
  output->writeByte(this->state);
  if(this->placementDate < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->placementDate << ") on element placementDate.";
  }
  output->writeInt((int)this->placementDate);
  if(this->nuggetsCount < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nuggetsCount << ") on element nuggetsCount.";
  }
  output->writeVarInt((int)this->nuggetsCount);
  if(this->durability < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->durability << ") on element durability.";
  }
  output->writeInt((int)this->durability);
  if(this->nextEvolutionDate < 0 || this->nextEvolutionDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextEvolutionDate << ") on element nextEvolutionDate.";
  }
  output->writeDouble(this->nextEvolutionDate);
}

void PrismInformation::deserialize(Reader *input)
{
  this->deserializeAs_PrismInformation(input);
}

void PrismInformation::deserializeAs_PrismInformation(Reader *input)
{
  this->_stateFunc(input);
  this->_placementDateFunc(input);
  this->_nuggetsCountFunc(input);
  this->_durabilityFunc(input);
  this->_nextEvolutionDateFunc(input);
}

void PrismInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismInformation(tree);
}

void PrismInformation::deserializeAsyncAs_PrismInformation(FuncTree tree)
{
  tree.addChild(std::bind(&PrismInformation::_stateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_placementDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_nuggetsCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_durabilityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_nextEvolutionDateFunc, this, std::placeholders::_1));
}

void PrismInformation::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->state << ") on element of PrismInformation.state.";
  }
}

void PrismInformation::_placementDateFunc(Reader *input)
{
  this->placementDate = input->readInt();
  if(this->placementDate < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->placementDate << ") on element of PrismInformation.placementDate.";
  }
}

void PrismInformation::_nuggetsCountFunc(Reader *input)
{
  this->nuggetsCount = input->readVarUhInt();
  if(this->nuggetsCount < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nuggetsCount << ") on element of PrismInformation.nuggetsCount.";
  }
}

void PrismInformation::_durabilityFunc(Reader *input)
{
  this->durability = input->readInt();
  if(this->durability < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->durability << ") on element of PrismInformation.durability.";
  }
}

void PrismInformation::_nextEvolutionDateFunc(Reader *input)
{
  this->nextEvolutionDate = input->readDouble();
  if(this->nextEvolutionDate < 0 || this->nextEvolutionDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextEvolutionDate << ") on element of PrismInformation.nextEvolutionDate.";
  }
}

PrismInformation::PrismInformation()
{
  m_types<<ClassEnum::PRISMINFORMATION;
}

bool PrismInformation::operator==(const PrismInformation &compared)
{
  if(state == compared.state)
  if(placementDate == compared.placementDate)
  if(nuggetsCount == compared.nuggetsCount)
  if(durability == compared.durability)
  if(nextEvolutionDate == compared.nextEvolutionDate)
  return true;
  
  return false;
}

