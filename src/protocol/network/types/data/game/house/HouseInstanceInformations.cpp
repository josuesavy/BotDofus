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
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->hasOwner);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->isSaleLocked);
  _box0 = BooleanByteWrapper::setFlag(_box0, 4, this->isAdminLocked);
  output->writeByte(_box0);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  this->ownerTag.serializeAs_AccountTagInformation(output);
  if(this->price < -9007199254740992 || this->price > 9007199254740992)
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
  this->ownerTag = AccountTagInformation();
  this->ownerTag.deserialize(input);
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
  this->_ownerTagtree = tree.addChild(std::bind(&HouseInstanceInformations::_ownerTagtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInstanceInformations::_priceFunc, this, std::placeholders::_1));
}

void HouseInstanceInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->secondHand = BooleanByteWrapper::getFlag(_box0, 0);
  this->isLocked = BooleanByteWrapper::getFlag(_box0, 1);
  this->hasOwner = BooleanByteWrapper::getFlag(_box0, 2);
  this->isSaleLocked = BooleanByteWrapper::getFlag(_box0, 3);
  this->isAdminLocked = BooleanByteWrapper::getFlag(_box0, 4);
}

void HouseInstanceInformations::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInstanceInformations -"<<"Forbidden value (" << this->instanceId << ") on element of HouseInstanceInformations.instanceId.";
  }
}

void HouseInstanceInformations::_ownerTagtreeFunc(Reader *input)
{
  this->ownerTag = AccountTagInformation();
  this->ownerTag.deserializeAsync(this->_ownerTagtree);
}

void HouseInstanceInformations::_priceFunc(Reader *input)
{
  this->price = input->readVarLong();
  if(this->price < -9007199254740992 || this->price > 9007199254740992)
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
  if(ownerTag == compared.ownerTag)
  if(hasOwner == compared.hasOwner)
  if(price == compared.price)
  if(isSaleLocked == compared.isSaleLocked)
  if(isAdminLocked == compared.isAdminLocked)
  if(_ownerTagtree == compared._ownerTagtree)
  return true;
  
  return false;
}

