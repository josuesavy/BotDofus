#include "AnomalySubareaInformation.h"

void AnomalySubareaInformation::serialize(Writer *output)
{
  this->serializeAs_AnomalySubareaInformation(output);
}

void AnomalySubareaInformation::serializeAs_AnomalySubareaInformation(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalySubareaInformation -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeVarShort((int)this->rewardRate);
  output->writeBool(this->hasAnomaly);
  if(this->anomalyClosingTime < 0 || this->anomalyClosingTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AnomalySubareaInformation -"<<"Forbidden value (" << this->anomalyClosingTime << ") on element anomalyClosingTime.";
  }
  output->writeVarLong((double)this->anomalyClosingTime);
}

void AnomalySubareaInformation::deserialize(Reader *input)
{
  this->deserializeAs_AnomalySubareaInformation(input);
}

void AnomalySubareaInformation::deserializeAs_AnomalySubareaInformation(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_rewardRateFunc(input);
  this->_hasAnomalyFunc(input);
  this->_anomalyClosingTimeFunc(input);
}

void AnomalySubareaInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AnomalySubareaInformation(tree);
}

void AnomalySubareaInformation::deserializeAsyncAs_AnomalySubareaInformation(FuncTree tree)
{
  tree.addChild(std::bind(&AnomalySubareaInformation::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AnomalySubareaInformation::_rewardRateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AnomalySubareaInformation::_hasAnomalyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AnomalySubareaInformation::_anomalyClosingTimeFunc, this, std::placeholders::_1));
}

void AnomalySubareaInformation::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AnomalySubareaInformation -"<<"Forbidden value (" << this->subAreaId << ") on element of AnomalySubareaInformation.subAreaId.";
  }
}

void AnomalySubareaInformation::_rewardRateFunc(Reader *input)
{
  this->rewardRate = input->readVarShort();
}

void AnomalySubareaInformation::_hasAnomalyFunc(Reader *input)
{
  this->hasAnomaly = input->readBool();
}

void AnomalySubareaInformation::_anomalyClosingTimeFunc(Reader *input)
{
  this->anomalyClosingTime = input->readVarUhLong();
  if(this->anomalyClosingTime < 0 || this->anomalyClosingTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AnomalySubareaInformation -"<<"Forbidden value (" << this->anomalyClosingTime << ") on element of AnomalySubareaInformation.anomalyClosingTime.";
  }
}

AnomalySubareaInformation::AnomalySubareaInformation()
{
  m_types<<ClassEnum::ANOMALYSUBAREAINFORMATION;
}

bool AnomalySubareaInformation::operator==(const AnomalySubareaInformation &compared)
{
  if(subAreaId == compared.subAreaId)
  if(rewardRate == compared.rewardRate)
  if(hasAnomaly == compared.hasAnomaly)
  if(anomalyClosingTime == compared.anomalyClosingTime)
  return true;
  
  return false;
}

