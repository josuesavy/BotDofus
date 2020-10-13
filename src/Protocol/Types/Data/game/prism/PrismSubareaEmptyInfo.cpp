#include "PrismSubareaEmptyInfo.h"

void PrismSubareaEmptyInfo::serialize(Writer *output)
{
  this->serializeAs_PrismSubareaEmptyInfo(output);
}

void PrismSubareaEmptyInfo::serializeAs_PrismSubareaEmptyInfo(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void PrismSubareaEmptyInfo::deserialize(Reader *input)
{
  this->deserializeAs_PrismSubareaEmptyInfo(input);
}

void PrismSubareaEmptyInfo::deserializeAs_PrismSubareaEmptyInfo(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_allianceIdFunc(input);
}

void PrismSubareaEmptyInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismSubareaEmptyInfo(tree);
}

void PrismSubareaEmptyInfo::deserializeAsyncAs_PrismSubareaEmptyInfo(FuncTree tree)
{
  tree.addChild(std::bind(&PrismSubareaEmptyInfo::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismSubareaEmptyInfo::_allianceIdFunc, this, std::placeholders::_1));
}

void PrismSubareaEmptyInfo::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSubareaEmptyInfo.subAreaId.";
  }
}

void PrismSubareaEmptyInfo::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->allianceId << ") on element of PrismSubareaEmptyInfo.allianceId.";
  }
}

PrismSubareaEmptyInfo::PrismSubareaEmptyInfo()
{
  m_types<<ClassEnum::PRISMSUBAREAEMPTYINFO;
}

bool PrismSubareaEmptyInfo::operator==(const PrismSubareaEmptyInfo &compared)
{
  if(subAreaId == compared.subAreaId)
  if(allianceId == compared.allianceId)
  return true;
  
  return false;
}

