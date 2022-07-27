#include "PrismInformation.h"

void PrismInformation::serialize(Writer *output)
{
  this->serializeAs_PrismInformation(output);
}

void PrismInformation::serializeAs_PrismInformation(Writer *output)
{
  if(this->typeId < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->typeId << ") on element typeId.";
  }
  output->writeByte(this->typeId);
  output->writeByte(this->state);
  if(this->nextVulnerabilityDate < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextVulnerabilityDate << ") on element nextVulnerabilityDate.";
  }
  output->writeInt((int)this->nextVulnerabilityDate);
  if(this->placementDate < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->placementDate << ") on element placementDate.";
  }
  output->writeInt((int)this->placementDate);
  if(this->rewardTokenCount < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->rewardTokenCount << ") on element rewardTokenCount.";
  }
  output->writeVarInt((int)this->rewardTokenCount);
}

void PrismInformation::deserialize(Reader *input)
{
  this->deserializeAs_PrismInformation(input);
}

void PrismInformation::deserializeAs_PrismInformation(Reader *input)
{
  this->_typeIdFunc(input);
  this->_stateFunc(input);
  this->_nextVulnerabilityDateFunc(input);
  this->_placementDateFunc(input);
  this->_rewardTokenCountFunc(input);
}

void PrismInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismInformation(tree);
}

void PrismInformation::deserializeAsyncAs_PrismInformation(FuncTree tree)
{
  tree.addChild(std::bind(&PrismInformation::_typeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_stateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_nextVulnerabilityDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_placementDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismInformation::_rewardTokenCountFunc, this, std::placeholders::_1));
}

void PrismInformation::_typeIdFunc(Reader *input)
{
  this->typeId = input->readByte();
  if(this->typeId < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->typeId << ") on element of PrismInformation.typeId.";
  }
}

void PrismInformation::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->state << ") on element of PrismInformation.state.";
  }
}

void PrismInformation::_nextVulnerabilityDateFunc(Reader *input)
{
  this->nextVulnerabilityDate = input->readInt();
  if(this->nextVulnerabilityDate < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextVulnerabilityDate << ") on element of PrismInformation.nextVulnerabilityDate.";
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

void PrismInformation::_rewardTokenCountFunc(Reader *input)
{
  this->rewardTokenCount = input->readVarUhInt();
  if(this->rewardTokenCount < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->rewardTokenCount << ") on element of PrismInformation.rewardTokenCount.";
  }
}

PrismInformation::PrismInformation()
{
  m_types<<ClassEnum::PRISMINFORMATION;
}

bool PrismInformation::operator==(const PrismInformation &compared)
{
  if(typeId == compared.typeId)
  if(state == compared.state)
  if(nextVulnerabilityDate == compared.nextVulnerabilityDate)
  if(placementDate == compared.placementDate)
  if(rewardTokenCount == compared.rewardTokenCount)
  return true;
  
  return false;
}

