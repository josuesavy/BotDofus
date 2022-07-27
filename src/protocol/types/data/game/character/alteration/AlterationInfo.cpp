#include "AlterationInfo.h"

void AlterationInfo::serialize(Writer *output)
{
  this->serializeAs_AlterationInfo(output);
}

void AlterationInfo::serializeAs_AlterationInfo(Writer *output)
{
  if(this->alterationId < 0 || this->alterationId > 4.294967295E9)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->alterationId << ") on element alterationId.";
  }
  output->writeUInt((uint)this->alterationId);
  if(this->creationTime < -9.007199254740992E15 || this->creationTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->creationTime << ") on element creationTime.";
  }
  output->writeDouble(this->creationTime);
  output->writeByte(this->expirationType);
  if(this->expirationValue < -9.007199254740992E15 || this->expirationValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->expirationValue << ") on element expirationValue.";
  }
  output->writeDouble(this->expirationValue);
  output->writeShort((short)this->effects.size());
  for(uint _i5 = 0; _i5 < this->effects.size(); _i5++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i5])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i5])->serialize(output);
  }
}

void AlterationInfo::deserialize(Reader *input)
{
  this->deserializeAs_AlterationInfo(input);
}

void AlterationInfo::deserializeAs_AlterationInfo(Reader *input)
{
  uint _id5 = 0;
  QSharedPointer<ObjectEffect> _item5 ;
  this->_alterationIdFunc(input);
  this->_creationTimeFunc(input);
  this->_expirationTypeFunc(input);
  this->_expirationValueFunc(input);
  uint _effectsLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _effectsLen; _i5++)
  {
    _id5 = input->readUShort();
    _item5 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id5));
    _item5->deserialize(input);
    this->effects.append(_item5);
  }
}

void AlterationInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlterationInfo(tree);
}

void AlterationInfo::deserializeAsyncAs_AlterationInfo(FuncTree tree)
{
  tree.addChild(std::bind(&AlterationInfo::_alterationIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AlterationInfo::_creationTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AlterationInfo::_expirationTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AlterationInfo::_expirationValueFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&AlterationInfo::_effectstreeFunc, this, std::placeholders::_1));
}

void AlterationInfo::_alterationIdFunc(Reader *input)
{
  this->alterationId = input->readUInt();
  if(this->alterationId < 0 || this->alterationId > 4.294967295E9)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->alterationId << ") on element of AlterationInfo.alterationId.";
  }
}

void AlterationInfo::_creationTimeFunc(Reader *input)
{
  this->creationTime = input->readDouble();
  if(this->creationTime < -9.007199254740992E15 || this->creationTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->creationTime << ") on element of AlterationInfo.creationTime.";
  }
}

void AlterationInfo::_expirationTypeFunc(Reader *input)
{
  this->expirationType = input->readByte();
  if(this->expirationType < 0)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->expirationType << ") on element of AlterationInfo.expirationType.";
  }
}

void AlterationInfo::_expirationValueFunc(Reader *input)
{
  this->expirationValue = input->readDouble();
  if(this->expirationValue < -9.007199254740992E15 || this->expirationValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlterationInfo -"<<"Forbidden value (" << this->expirationValue << ") on element of AlterationInfo.expirationValue.";
  }
}

void AlterationInfo::_effectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&AlterationInfo::_effectsFunc, this, std::placeholders::_1));
  }
}

void AlterationInfo::_effectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

AlterationInfo::AlterationInfo()
{
  m_types<<ClassEnum::ALTERATIONINFO;
}

bool AlterationInfo::operator==(const AlterationInfo &compared)
{
  if(alterationId == compared.alterationId)
  if(creationTime == compared.creationTime)
  if(expirationType == compared.expirationType)
  if(expirationValue == compared.expirationValue)
  if(effects == compared.effects)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

