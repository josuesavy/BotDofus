#include "HumanOptionObjectUse.h"

void HumanOptionObjectUse::serialize(Writer *output)
{
  this->serializeAs_HumanOptionObjectUse(output);
}

void HumanOptionObjectUse::serializeAs_HumanOptionObjectUse(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  output->writeByte(this->delayTypeId);
  if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayEndTime << ") on element delayEndTime.";
  }
  output->writeDouble(this->delayEndTime);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
}

void HumanOptionObjectUse::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionObjectUse(input);
}

void HumanOptionObjectUse::deserializeAs_HumanOptionObjectUse(Reader *input)
{
  HumanOption::deserialize(input);
  this->_delayTypeIdFunc(input);
  this->_delayEndTimeFunc(input);
  this->_objectGIDFunc(input);
}

void HumanOptionObjectUse::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionObjectUse(tree);
}

void HumanOptionObjectUse::deserializeAsyncAs_HumanOptionObjectUse(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionObjectUse::_delayTypeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionObjectUse::_delayEndTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionObjectUse::_objectGIDFunc, this, std::placeholders::_1));
}

void HumanOptionObjectUse::_delayTypeIdFunc(Reader *input)
{
  this->delayTypeId = input->readByte();
  if(this->delayTypeId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayTypeId << ") on element of HumanOptionObjectUse.delayTypeId.";
  }
}

void HumanOptionObjectUse::_delayEndTimeFunc(Reader *input)
{
  this->delayEndTime = input->readDouble();
  if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayEndTime << ") on element of HumanOptionObjectUse.delayEndTime.";
  }
}

void HumanOptionObjectUse::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->objectGID << ") on element of HumanOptionObjectUse.objectGID.";
  }
}

HumanOptionObjectUse::HumanOptionObjectUse()
{
  m_types<<ClassEnum::HUMANOPTIONOBJECTUSE;
}

bool HumanOptionObjectUse::operator==(const HumanOptionObjectUse &compared)
{
  if(delayTypeId == compared.delayTypeId)
  if(delayEndTime == compared.delayEndTime)
  if(objectGID == compared.objectGID)
  return true;
  
  return false;
}

