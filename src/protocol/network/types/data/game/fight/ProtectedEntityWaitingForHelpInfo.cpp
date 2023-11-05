#include "ProtectedEntityWaitingForHelpInfo.h"

void ProtectedEntityWaitingForHelpInfo::serialize(Writer *output)
{
  this->serializeAs_ProtectedEntityWaitingForHelpInfo(output);
}

void ProtectedEntityWaitingForHelpInfo::serializeAs_ProtectedEntityWaitingForHelpInfo(Writer *output)
{
  output->writeInt((int)this->timeLeftBeforeFight);
  output->writeInt((int)this->waitTimeForPlacement);
  if(this->nbPositionForDefensors < 0)
  {
    qDebug()<<"ERREUR - ProtectedEntityWaitingForHelpInfo -"<<"Forbidden value (" << this->nbPositionForDefensors << ") on element nbPositionForDefensors.";
  }
  output->writeByte(this->nbPositionForDefensors);
}

void ProtectedEntityWaitingForHelpInfo::deserialize(Reader *input)
{
  this->deserializeAs_ProtectedEntityWaitingForHelpInfo(input);
}

void ProtectedEntityWaitingForHelpInfo::deserializeAs_ProtectedEntityWaitingForHelpInfo(Reader *input)
{
  this->_timeLeftBeforeFightFunc(input);
  this->_waitTimeForPlacementFunc(input);
  this->_nbPositionForDefensorsFunc(input);
}

void ProtectedEntityWaitingForHelpInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ProtectedEntityWaitingForHelpInfo(tree);
}

void ProtectedEntityWaitingForHelpInfo::deserializeAsyncAs_ProtectedEntityWaitingForHelpInfo(FuncTree tree)
{
  tree.addChild(std::bind(&ProtectedEntityWaitingForHelpInfo::_timeLeftBeforeFightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ProtectedEntityWaitingForHelpInfo::_waitTimeForPlacementFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ProtectedEntityWaitingForHelpInfo::_nbPositionForDefensorsFunc, this, std::placeholders::_1));
}

void ProtectedEntityWaitingForHelpInfo::_timeLeftBeforeFightFunc(Reader *input)
{
  this->timeLeftBeforeFight = input->readInt();
}

void ProtectedEntityWaitingForHelpInfo::_waitTimeForPlacementFunc(Reader *input)
{
  this->waitTimeForPlacement = input->readInt();
}

void ProtectedEntityWaitingForHelpInfo::_nbPositionForDefensorsFunc(Reader *input)
{
  this->nbPositionForDefensors = input->readByte();
  if(this->nbPositionForDefensors < 0)
  {
    qDebug()<<"ERREUR - ProtectedEntityWaitingForHelpInfo -"<<"Forbidden value (" << this->nbPositionForDefensors << ") on element of ProtectedEntityWaitingForHelpInfo.nbPositionForDefensors.";
  }
}

ProtectedEntityWaitingForHelpInfo::ProtectedEntityWaitingForHelpInfo()
{
  m_types<<ClassEnum::PROTECTEDENTITYWAITINGFORHELPINFO;
}

bool ProtectedEntityWaitingForHelpInfo::operator==(const ProtectedEntityWaitingForHelpInfo &compared)
{
  if(timeLeftBeforeFight == compared.timeLeftBeforeFight)
  if(waitTimeForPlacement == compared.waitTimeForPlacement)
  if(nbPositionForDefensors == compared.nbPositionForDefensors)
  return true;
  
  return false;
}

