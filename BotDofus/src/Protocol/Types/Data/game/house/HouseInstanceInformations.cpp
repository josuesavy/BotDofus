#include "HouseInstanceInformations.h"

void HouseInstanceInformations::serialize(Writer *output)
{
  this->serializeAs_HouseInstanceInformations(output);
}

void HouseInstanceInformations::serializeAs_HouseInstanceInformations(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->secondHand);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isLocked);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->isSaleLocked);
  output->writeByte(_box0);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeUTF(this->ownerName);
  if(this->price < -9.007199254740992E15 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void HouseInstanceInformations::deserialize(Reader *input)
{
  this->deserializeAs_HouseInstanceInformations(input);
}

void HouseInstanceInformations::deserializeAs_HouseInstanceInformations(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_instanceIdFunc(input);
  this->_ownerNameFunc(input);
  this->_priceFunc(input);
}

void HouseInstanceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseInstanceInformations(tree);
}

void HouseInstanceInformations::deserializeAsyncAs_HouseInstanceInformations(FuncTree tree)
{
  tree.addChild(std::bind(&HouseInstanceInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInstanceInformations::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInstanceInformations::_ownerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInstanceInformations::_priceFunc, this, std::placeholders::_1));
}

void HouseInstanceInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->secondHand = BooleanByteWrapper::getFlag(_box0, 0);
  this->isLocked = BooleanByteWrapper::getFlag(_box0, 1);
  this->isSaleLocked = BooleanByteWrapper::getFlag(_box0, 2);
}

void HouseInstanceInformations::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->instanceId << ") on element of HouseInstanceInformations.instanceId.";
  }
}

void HouseInstanceInformations::_ownerNameFunc(Reader *input)
{
  this->ownerName = input->readUTF();
}

void HouseInstanceInformations::_priceFunc(Reader *input)
{
  this->price = input->readVarLong();
  if(this->price < -9.007199254740992E15 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->price << ") on element of HouseInstanceInformations.price.";
  }
}

HouseInstanceInformations::HouseInstanceInformations()
{
  m_types<<ClassEnum::HOUSEINSTANCEINFORMATIONS;
}

bool HouseInstanceInformations::operator==(const HouseInstanceInformations &compared)
{
  if(instanceId == compared.instanceId)
  if(secondHand == compared.secondHand)
  if(isLocked == compared.isLocked)
  if(ownerName == compared.ownerName)
  if(price == compared.price)
  if(isSaleLocked == compared.isSaleLocked)
  return true;
  
  return false;
}

